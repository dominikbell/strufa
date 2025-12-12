#pragma once

#include <string>

struct Input {
  const std::string model_name = "";
  const std::string file_name = "";
  const int file_name_length = 0;
};

void assert_only_one_input(char* argv[]);
void assert_valid_file(std::string& filename, const int filename_length);
Input parse_input(char* argv[]);