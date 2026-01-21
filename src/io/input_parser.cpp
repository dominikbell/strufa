#include "input_parser.hpp"

#include <cassert>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <utility>

#include "models/base/models.hpp"
#include "utilities/dimensions.hpp"
#include "utilities/utilities.hpp"

namespace fs = std::filesystem;

std::string get_file_path(const std::string& filename) {
  std::string filepath {"../" + filename};
  return filepath;
}

void assert_only_one_input(char* argv[]) {
  // TODO: make sure that only one string is passed (multiple inputs not supported yet)
}

void assert_valid_file(std::string& filename, const int filename_length) {
  // Check if passed filename has json format
  bool file_has_json_format {
      filename[filename_length - 5] == '.' &&
      filename[filename_length - 4] == 'j' &&
      filename[filename_length - 3] == 's' &&
      filename[filename_length - 2] == 'o' &&
      filename[filename_length - 1] == 'n' &&
      "Filename must end with .json"};
  assert(file_has_json_format);

  // Make sure that the given file actually exists
  std::string filepath {get_file_path(filename)};
  bool file_exists {fs::exists(filepath) && "Given file does not exist!"};
  assert(file_exists);
}

void assert_top_level_keyword(const json& data, const std::string& keyword) {
  bool contains_keyword {data.count(keyword) == 1};
  if (!contains_keyword) {
    std::cout << "Parameters file must contain top-level keyword '" << keyword << "'!\n";
    assert(data.count(keyword) == 1 && "Top-level keyword missing in parameter file; check the line above.");
  }
}

void assert_second_level_keyword(const json& data, const std::string& parent_keyword, const std::string& keyword) {
  bool contains_keyword {data[parent_keyword].count(keyword) == 1};
  if (!contains_keyword) {
    std::cout << "Parameters file must contain keyword '" << keyword << "' under top-level keyword '" << parent_keyword << "'!\n";
    assert(data[parent_keyword].count(keyword) == 1 && "Second-level keyword missing in parameter file; check the line above.");
  }
}

void assert_keyword_not_zero(const json& data, const std::string& keyword) {
  bool is_zero {data[keyword] == 0.0};
  if (is_zero) {
    std::cout << keyword << " was detected to be zero in dictionary but must be non-zero!\n";
    assert((data[keyword] == 0.0) && "Zero-value detected; check the line above." );
  }
}

void assert_not_zero(double value, const std::string& name) {
  bool is_zero {value == 0.0};
  if (is_zero) {
    std::cout << name << " was detected to be zero but must be non-zero!\n";
    assert((value == 0.0) && "Zero-value detected; check the line above." );
  }
}

json open_file(const std::string& filename) {
  // Get the file path and open the stream
  std::string filepath {get_file_path(filename)};
  std::ifstream fileStream(filepath);

  // Check if file is being edited right now
  if (!fileStream.is_open()) {
    std::cerr << "Error: Could not open file " << filename << '\n';
  }

  try {
    json data = json::parse(fileStream);
    return data;

  } catch (const json::parse_error& e) {
    std::cerr << "JSON Parse Error: " << e.what() << " at byte " << e.byte << '\n';
    exit_with_failure("Problem with reading the json file, see error log for details.");
  }
}

Input parse_input(char* argv[]) {
  // First argument should be filename
  std::string filename {static_cast<std::string>(argv[1])};
  const int filename_length {static_cast<int>(filename.length())};

  // Assert that the file has json format and exists
  assert_valid_file(filename, filename_length);

  json data {open_file(filename)};
  std::string model_name {data["model"]};
  const ModelVariant model {string_to_model(model_name)};

  // Make
  const std::pair<int, int> pair_dimensions {get_space_and_velocity_dimensions(data)};
  const DimensionsVariant dimensions {get_dimensions(pair_dimensions)};

  return {model, dimensions, filename, filename_length, data};
}

int get_space_dimensions(const Input& input) {
  json data {open_file(input.file_name)};
  std::string key_space = "space_dimensions";
  assert(
      data.count(key_space) == 1 &&
      "DomainParameters file must indicate the space dimensions!");
  return data[key_space];
}

int get_velocity_dimensions(const Input& input) {
  json data {open_file(input.file_name)};
  std::string key_velocity = "velocity_dimensions";
  assert(
      data.count(key_velocity) == 1 &&
      "DomainParameters file must indicate the velocity dimensions!");
  return data[key_velocity];
}

std::pair<int, int> get_space_and_velocity_dimensions(const json& data) {
  std::string key_space = "space_dimensions";
  std::string key_velocity = "velocity_dimensions";
  assert(
      data.count(key_space) == 1 &&
      "Parameters file must indicate the space dimensions!");
  int space_dimensions {data[key_space]};

  // If key_velocity is not found, assume model has zero velocity dimensions
  int velocity_dimensions {data.value(key_velocity, 0)};
  return std::make_pair(space_dimensions, velocity_dimensions);
}
