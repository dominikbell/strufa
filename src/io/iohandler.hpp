#pragma once

#include "parameters/parameters.hpp"

std::optional<Parameters> readParameterFile(std::string& filename, const int filename_length);