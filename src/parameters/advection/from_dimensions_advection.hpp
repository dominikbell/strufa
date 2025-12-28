#pragma once

#include "utilities/dimensions.hpp"
#include "parameters_advection.hpp"
#include "parameters/parameters.hpp"

struct ParametersAdvection1D1V;
struct ParametersAdvection1D2V;

// Template trait
template <typename T>
struct DimensionToParameter;

template <>
struct DimensionToParameter<Dimensions1D1V> {
  using parameters_type = ParametersAdvection1D1V;
  using space_parameters_type = Parameters1D;
};
template <>
struct DimensionToParameter<Dimensions1D2V> {
  using parameters_type = ParametersAdvection1D2V;
  using space_parameters_type = Parameters1D;
};
