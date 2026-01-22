#pragma once

#include <variant>

#include "advection/parameters_advection.hpp"
#include "io/input_parser.hpp"
#include "models/models.hpp"
#include "poisson/parameters_poisson.hpp"
#include "utilities/dimensions.hpp"

using ParametersVariant = std::variant<
    AdvectionParametersVariant,
    PoissonParametersVariant>;

ParametersVariant get_parameters(
    const ModelVariant& model_variant,
    const DimensionsVariant& dimensions_variant,
    const json& data);

template <typename TModel>
ParametersVariant get_parameters(const DimensionsVariant& dimensions_variant, const json& data);
