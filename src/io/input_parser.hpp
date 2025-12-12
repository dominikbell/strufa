#pragma once

#include <string>

#include "base_models.hpp"

struct Input {
  const Model model;
  const std::string file_name = "";
  const int file_name_length = 0;
};

void assert_only_one_input(char* argv[]);
void assert_valid_file(std::string& filename, const int filename_length);
Input parse_input(char* argv[]);