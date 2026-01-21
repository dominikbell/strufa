#pragma once

#include "io/input_parser.hpp"
#include "models/base/models.hpp"
#include "parameters/parameters.hpp"

template <>
ParametersVariant get_parameters<Advection>(
    const DimensionsVariant& dimensions_variant,
    const json& data);
