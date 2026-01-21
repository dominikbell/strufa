#pragma once

#include <nlohmann/json.hpp>
#include <string>

#include "models/base/models.hpp"
#include "utilities/dimensions.hpp"

using json = nlohmann::json;

struct Input {
  const ModelVariant model_variant;
  const DimensionsVariant dimensions_variant;
  const std::string file_name = "";
  const int file_name_length = 0;
  const json file;
};

void assert_only_one_input(char* argv[]);
void assert_valid_file(std::string& filename, const int filename_length);
void assert_top_level_keyword(const json& data, const std::string& keyword);
void assert_second_level_keyword(const json& data, const std::string& parent_keyword, const std::string& keyword);
void assert_not_zero(double value, std::string& name);
void assert_keyword_not_zero(const json& data, const std::string& keyword);
json open_file(const std::string& filename);
Input parse_input(char* argv[]);
int get_space_dimensions(const Input& input);
int get_velocity_dimensions(const Input& input);
std::pair<int, int> get_space_and_velocity_dimensions(const json& data);
