#include <optional>
#include <iostream>
#include <fstream>
#include <filesystem>

#include <nlohmann/json.hpp>

#include "parameters/parameters.hpp"

namespace fs = std::filesystem;
using json = nlohmann::json;

std::optional<Parameters> readParameterFile(std::string& filename, const int filename_length)
{
  // Check if passed filename has json format
  bool file_has_json_format {
    filename[filename_length - 5] == '.'
    && filename[filename_length - 4] == 'j'
    && filename[filename_length - 3] == 's'
    && filename[filename_length - 2] == 'o'
    && filename[filename_length - 1] == 'n'
    // && "Filename must end with .json"
  };

  // Make sure that the given file actually exists
  std::string filepath { "../" + filename };
  bool file_exists {
    fs::exists(filepath)
    // && "Given file does not exist!")
  };

  if (file_exists && file_has_json_format){
    std::ifstream fileStream(filepath);

    // Check is file is used being edited right now
    if (!fileStream.is_open()) {
      std::cerr << "Error: Could not open file " << filename << '\n';
      return std::nullopt;
    }

    try {
      json data = json::parse(fileStream);
      Parameters p { data["model"] };
      return p;

    } catch (const json::parse_error& e) {
      std::cerr << "JSON Parse Error: " << e.what() << " at byte " << e.byte << '\n';
      return std::nullopt;
    }
  } else {
    return std::nullopt;
  }
}
