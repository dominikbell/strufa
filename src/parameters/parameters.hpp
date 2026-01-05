#pragma once

#include <utility>
#include <variant>

#include "advection/parameters_advection.hpp"
#include "io/input_parser.hpp"
#include "models/base/models.hpp"
#include "poisson/parameters_poisson.hpp"
#include "io/input_parser.hpp"

using ParametersVariant = std::variant<
    AdvectionParametersVariant,
    PoissonParametersVariant>;

ParametersVariant get_parameters(
    const ModelEnum& model_enum,
    std::pair<int, int> pair_dimensions,
    const json& data);
