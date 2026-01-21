#pragma once

#include <variant>

#include "advection/parameters_advection.hpp"
#include "utilities/dimensions.hpp"
#include "io/input_parser.hpp"
#include "models/base/models.hpp"
#include "poisson/parameters_poisson.hpp"

using ParametersVariant = std::variant<
    AdvectionParametersVariant,
    PoissonParametersVariant>;

ParametersVariant get_parameters(
    const ModelVariant& model_variant,
    const DimensionsVariant& dimensions_variant,
    const json& data);

template <typename TModel>
ParametersVariant get_parameters(const DimensionsVariant& dimensions_variant, const json& data);
