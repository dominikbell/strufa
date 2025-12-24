#pragma once

#include <variant>

#include "parameters/parameters_advection.hpp"
#include "parameters_to_variables_advection.hpp"
#include "particles/particles.hpp"

struct Variables_Advection_1D1V {
  Particles_1D1V particles;

  // Constructor
  Variables_Advection_1D1V(
      Parameters_Advection_1D1V parameters_i)
      : particles(static_cast<ParticleParameters>(parameters_i)) {};

  // Default the Copy Constructor
  Variables_Advection_1D1V(const Variables_Advection_1D1V& other) = default;

  // Default the Move Constructor (most critical for return values)
  Variables_Advection_1D1V(Variables_Advection_1D1V&& other) noexcept = default;
};

struct Variables_Advection_1D2V {
  Particles_1D2V particles;

  // Constructor
  Variables_Advection_1D2V(
      Parameters_Advection_1D2V parameters_i)
      : particles(static_cast<ParticleParameters>(parameters_i)) {};

  // Default the Copy Constructor
  Variables_Advection_1D2V(const Variables_Advection_1D2V& other) = default;

  // Default the Move Constructor (most critical for return values)
  Variables_Advection_1D2V(Variables_Advection_1D2V&& other) noexcept = default;
};

using Advection_Variables_Type = std::variant<Variables_Advection_1D1V, Variables_Advection_1D2V>;

// Variables_Advection_1D1V get_variables_dimensionful(const Parameters_Advection_1D1V& parameters);
// Variables_Advection_1D2V get_variables_dimensionful(const Parameters_Advection_1D2V& parameters);
Advection_Variables_Type get_variables(const Advection_Parameters_Type& parameters);

template <typename T_in>
auto get_variables_dimensionful(const T_in& parameters) {
  using T_out = typename ParameterToVariable<T_in>::type;
  return T_out {parameters};
}
