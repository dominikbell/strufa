#pragma once

#include <variant>

#include "parameters/advection/parameters_advection.hpp"
#include "from_parameters_advection.hpp"
#include "particles/particles.hpp"

struct VariablesAdvection1D1V {
  Particles1D1V particles;

  // Constructor
  VariablesAdvection1D1V(
      ParametersAdvection1D1V parameters_i)
      : particles(static_cast<ParticleParameters>(parameters_i)) {};

  // Default the Copy Constructor
  VariablesAdvection1D1V(const VariablesAdvection1D1V& other) = default;

  // Default the Move Constructor (most critical for return values)
  VariablesAdvection1D1V(VariablesAdvection1D1V&& other) noexcept = default;
};

struct VariablesAdvection1D2V {
  Particles_1D2V particles;

  // Constructor
  VariablesAdvection1D2V(
      ParametersAdvection1D2V parameters_i)
      : particles(static_cast<ParticleParameters>(parameters_i)) {};

  // Default the Copy Constructor
  VariablesAdvection1D2V(const VariablesAdvection1D2V& other) = default;

  // Default the Move Constructor (most critical for return values)
  VariablesAdvection1D2V(VariablesAdvection1D2V&& other) noexcept = default;
};

using AdvectionVariablesType = std::variant<VariablesAdvection1D1V, VariablesAdvection1D2V>;

AdvectionVariablesType get_variables(const AdvectionParametersType& parameters);

template <typename T_in>
auto get_variables_dimensionful(const T_in& parameters) {
  using T_out = typename ParameterToVariable<T_in>::type;
  return T_out {parameters};
}
