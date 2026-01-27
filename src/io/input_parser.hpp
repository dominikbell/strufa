#pragma once

#include <filesystem>
#include <nlohmann/json.hpp>
#include <string>

#include "models/models.hpp"
#include "utilities/dimensions.hpp"

using json = nlohmann::json;

namespace fs = std::filesystem;

struct Input {
  const ModelVariant model_variant;
  const DimensionsVariant dimensions_variant;
  const std::string input_file_name = "";
  const int input_file_name_length = 0;
  const fs::path output_path = "";
  const json file;
};

void assert_only_one_input(char* argv[]);
void assert_valid_file(const std::string& filename, const int filename_length);
fs::path make_output_path(const std::string& output_folder);
fs::path get_valid_output_path();
void assert_top_level_keyword(const json& data, const std::string& keyword);
void assert_second_level_keyword(const json& data, const std::string& parent_keyword, const std::string& keyword);
void assert_not_zero(double value, std::string& name);
void assert_keyword_not_zero(const json& data, const std::string& keyword);
json open_file(const std::string& filename);
Input parse_input(int argc, char* argv[]);
int get_space_dimensions(const Input& input);
int get_velocity_dimensions(const Input& input);
std::pair<int, int> get_space_and_velocity_dimensions(const json& data);
