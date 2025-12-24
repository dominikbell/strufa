#pragma once

#include "parameters/parameters.hpp"
#include "variables_advection.hpp"

struct Parameters_Advection_1D1V;
struct Parameters_Advection_1D2V;

struct Variables_Advection_1D1V;
struct Variables_Advection_1D2V;

template <typename T>
struct ParameterToVariable;

template <>
struct ParameterToVariable<Parameters_Advection_1D1V> {
  using type = Variables_Advection_1D1V;
};
template <>
struct ParameterToVariable<Parameters_Advection_1D2V> {
  using type = Variables_Advection_1D2V;
};
