#pragma once

#include <nlohmann/json.hpp>
#include <string>

#include "models/base_models/base_models.hpp"

using json = nlohmann::json;

struct Input {
  const Model model;
  const std::string file_name = "";
  const int file_name_length = 0;
};

void assert_only_one_input(char* argv[]);
void assert_valid_file(std::string& filename, const int filename_length);
json open_file(const std::string& filename);
Input parse_input(char* argv[]);
int get_space_dimensions(const Input& input);
int get_velocity_dimensions(const Input& input);
std::pair<int, int> get_space_and_velocity_dimensions(const Input& input);