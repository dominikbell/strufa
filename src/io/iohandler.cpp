#include <iostream>
#include <fstream>
#include <filesystem>

#include <nlohmann/json.hpp>

namespace fs = std::filesystem;
using json = nlohmann::json;

void readParameterFile(std::string& filename, const int filename_length)
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
      return;
    }

    try {
      json data = json::parse(fileStream);
      std::string model = data["model"];
      std::cout << "The model name is " << model << '\n';
    } catch (const json::parse_error& e) {
        std::cerr << "JSON Parse Error: " << e.what() << " at byte " << e.byte << '\n';
    }
  }
}

void readFile_1()
{
  // Path must be relative to main.cpp
  std::ifstream inputFile("../example.txt");

  if (inputFile.is_open()) {
    std::string line;

    std::cout << "Opened file, now reading its content ...\n\n";

    while (std::getline(inputFile, line)) {
      std::cout << line << '\n';
    }
    std::cout << '\n';

    inputFile.close();
    std::cout << "Finished reading the file and closed it.\n";
  } else {
    std::cerr << "Unable to open the file!";
  }
}