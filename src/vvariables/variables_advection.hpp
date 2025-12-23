#pragma once

#include <variant>

#include "particles/particles.hpp"
#include "parameters/parameters_advection.hpp"

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

using Advection_Variables_Type = std::variant<Variables_Advection_1D1V>;

Advection_Variables_Type get_variables(const Advection_Parameters_Type& parameters);
Variables_Advection_1D1V get_variables_dimensionful(const Parameters_Advection_1D1V& parameters);
