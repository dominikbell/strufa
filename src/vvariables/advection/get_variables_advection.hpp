#pragma once

#include <algorithm>
#include "models/models.hpp"
#include "vvariables/model_variables.hpp"
#include "parameters/model_parameters.hpp"
#include "particles/particles.hpp"

template <typename Dimensions>
inline Variables<Advection, Dimensions>
get_variables(const Parameters<Advection, Dimensions>& parameters) {
  Particles<Dimensions, FullF> particles {
    parameters.particle_parameters,
    "particles",
    parameters.time_parameters,
    "particles"
  };

  return {std::move(particles)};
}
