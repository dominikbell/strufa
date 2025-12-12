#include "input_parser.hpp"
#include "base_models.hpp"

#include <cassert>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <optional>
#include <nlohmann/json.hpp>

namespace fs = std::filesystem;
using json = nlohmann::json;

std::string get_file_path(std::string& filename) {
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

Input parse_input(char* argv[]) {
  // First argument should be filename
  std::string filename {static_cast<std::string>(argv[1])};
  const int filename_length {static_cast<int>(filename.length())};

  // Assert that the file has json format and exists
  assert_valid_file(filename, filename_length);

  std::string filepath {get_file_path(filename)};
  std::ifstream fileStream(filepath);

  // Check is file is< used being edited right now
  if (!fileStream.is_open()) {
    std::cerr << "Error: Could not open file " << filename << '\n';
  }

  try {
    json data = json::parse(fileStream);
    std::string model_name {data["model"]};
    const std::optional<Model> model {string_to_model(model_name)};
    if (model) {
      Input input {*model, filename, filename_length};
      return input;
    } else {
      std::cerr << "Invalid model name entered, exiting.\n";
    }

  } catch (const json::parse_error& e) {
    std::cerr << "JSON Parse Error: " << e.what() << " at byte " << e.byte << '\n';
  }
}