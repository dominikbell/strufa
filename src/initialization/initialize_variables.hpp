#pragma once

#include "io/input_parser.hpp"
#include "parameters/domain_parameters.hpp"
#include "vvariables/vvariables.hpp"

void initialize_variables(
    std::pair<int, int> pair_dimensions,
    VariablesVariant& variables,
    const json& data,
    const DomainParametersVariant& domain_parameters);
