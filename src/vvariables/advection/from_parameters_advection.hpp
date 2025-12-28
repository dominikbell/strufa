#pragma once

#include "parameters/parameters.hpp"
#include "variables_advection.hpp"

struct ParametersAdvection1D1V;
struct ParametersAdvection1D2V;

struct VariablesAdvection1D1V;
struct VariablesAdvection1D2V;

// Template trait
template <typename T>
struct ParameterToVariable;

template <>
struct ParameterToVariable<ParametersAdvection1D1V> {
  using type = VariablesAdvection1D1V;
};
template <>
struct ParameterToVariable<ParametersAdvection1D2V> {
  using type = VariablesAdvection1D2V;
};
