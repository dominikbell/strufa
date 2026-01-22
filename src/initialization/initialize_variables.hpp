#pragma once

#include "io/input_parser.hpp"
#include "parameters/parameters.hpp"
#include "vvariables/vvariables.hpp"

void initialize_variables(
    VariablesVariant& variables_variant,
    const ParametersVariant& parameters_variant,
    const json& data);
