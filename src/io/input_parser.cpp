#include "input_parser.hpp"

#include <cassert>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include <utility>

#include "models/models.hpp"
#include "utilities/dimensions.hpp"
#include "utilities/utilities.hpp"

std::string get_file_path(const std::string& filename) {
  std::string filepath {"../" + filename};
  return filepath;
}

void assert_only_one_input(char* argv[]) {
  // TODO: make sure that only one string is passed (multiple inputs not supported yet)
}

void assert_valid_file(const std::string& filename, const int filename_length) {
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

fs::path make_output_path(const std::string& output_folder) {
  // TODO: this only works when the script is being run from inside the build directory
  const fs::path parent_path = fs::path("../out");
  if (!fs::exists(parent_path)) {
    fs::create_directory(parent_path);
  }
  return parent_path / output_folder;
}

fs::path get_valid_output_path() {
  int i {0};
  while (true) {
    std::string output_folder = "simulation_" + std::to_string(i);
    fs::path output_path {make_output_path(output_folder)};
    if (fs::exists(output_path)) {
      ++i;
    } else {
      fs::create_directory(output_path);
      return output_path;
    }
  }
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
    assert((data[keyword] == 0.0) && "Zero-value detected; check the line above.");
  }
}

void assert_not_zero(double value, const std::string& name) {
  bool is_zero {value == 0.0};
  if (is_zero) {
    std::cout << name << " was detected to be zero but must be non-zero!\n";
    assert((value == 0.0) && "Zero-value detected; check the line above.");
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

Input parse_input(int argc, char* argv[]) {
  // argv[0] is always path of the script, the next argument must be the name of the input file
  const std::string filename {static_cast<std::string>(argv[1])};
  const int filename_length {static_cast<int>(filename.length())};

  // Assert that the file has json format and exists
  assert_valid_file(filename, filename_length);
  std::cout << "Got parameter file " << filename << '\n';

  // Get the model
  json data {open_file(filename)};
  std::string model_name {data["model"]};
  const ModelVariant model {get_model(model_name)};

  // Get the dimensions
  const std::pair<int, int> pair_dimensions {get_space_and_velocity_dimensions(data)};
  const DimensionsVariant dimensions {get_dimensions(pair_dimensions)};

  // If additional input is given, parse it
  if (argc > 2) {
    std::string output_folder_name {""};
    for (size_t i = 2; i < static_cast<size_t>(argc); ++i) {
      std::string argument {static_cast<std::string>(argv[i])};

      if (argument == "-o" && argc > i + 1) {
        output_folder_name = static_cast<std::string>(argv[i + 1]);
      }
    }

    fs::path output_path {};
    if (output_folder_name.empty()) {
      fs::path output_path {get_valid_output_path()};
    } else {
      output_path = make_output_path(output_folder_name);
      // Clear the folder if it exists
      if (fs::exists(output_path)) {
        fs::remove_all(output_path);
      }
      fs::create_directory(output_path);
    }
    std::cout << "Saving into " << static_cast<std::string>(output_path).substr(3) << '\n';

    return {model, dimensions, filename, filename_length, output_path, data};
  } else {
    // Get the output folder
    fs::path output_path {get_valid_output_path()};
    std::cout << "Saving into " << output_path << '\n';

    return {model, dimensions, filename, filename_length, output_path, data};
  }
}

int get_space_dimensions(const Input& input) {
  json data {open_file(input.input_file_name)};
  std::string key_space = "space_dimensions";
  assert(
      data.count(key_space) == 1 &&
      "DomainParameters file must indicate the space dimensions!");
  return data[key_space];
}

int get_velocity_dimensions(const Input& input) {
  json data {open_file(input.input_file_name)};
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
