#pragma once

#include "particles/particles.hpp"

struct Variables_Advection_1D1V {
  Particles_1D1V particles;

  // Constructor
  Variables_Advection_1D1V(long N_markers, int seed) : particles(N_markers, seed) {};

  // Default the Copy Constructor
  Variables_Advection_1D1V(const Variables_Advection_1D1V& other) = default;

  // Default the Move Constructor (most critical for return values)
  Variables_Advection_1D1V(Variables_Advection_1D1V&& other) noexcept = default;
};