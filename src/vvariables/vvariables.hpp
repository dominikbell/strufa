#pragma once

#include <variant>

#include "advection/variables_advection.hpp"
#include "io/input_parser.hpp"
#include "parameters/parameters.hpp"
#include "poisson/variables_poisson.hpp"

using VariablesVariant = std::variant<
    AdvectionVariablesVariant,
    PoissonVariablesVariant>;

VariablesVariant get_variables(const ParametersVariant& parameters, const Input& input);
