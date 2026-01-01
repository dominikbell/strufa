#pragma once

#include <variant>

#include "advection/variables_advection.hpp"
#include "parameters/parameters.hpp"
#include "poisson/variables_poisson.hpp"

using VariablesVariant = std::variant<
    AdvectionVariablesVariant,
    PoissonVariablesVariant>;

VariablesVariant get_variables(std::pair<int, int> pair_dimensions, const ParametersVariant& parameters);
