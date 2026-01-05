#pragma once

#include "io/input_parser.hpp"
#include "vvariables/vvariables.hpp"

void initialize_variables(std::pair<int, int> pair_dimensions, VariablesVariant& variables, const json& data);
