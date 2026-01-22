#pragma once

#include "io/input_parser.hpp"
#include "models/models.hpp"
#include "parameters/parameters.hpp"

template <>
ParametersVariant get_parameters<Poisson>(
    const DimensionsVariant& dimensions_variant,
    const json& data);
