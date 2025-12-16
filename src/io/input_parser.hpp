#pragma once

#include <string>

#include "models/base_models/base_models.hpp"

struct Input {
  const Model model;
  const std::string file_name = "";
  const int file_name_length = 0;
};

void assert_only_one_input(char* argv[]);
void assert_valid_file(std::string& filename, const int filename_length);
Input parse_input(char* argv[]);
int get_space_dimensions(const Input& input);
int get_velocity_dimensions(const Input& input);
std::pair<int, int> get_space_and_velocity_dimensions(const Input& input);