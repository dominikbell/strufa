#pragma once

#include <algorithm>

#include "io/input_parser.hpp"
#include "models/models.hpp"
#include "parameters/model_parameters.hpp"
#include "particles/particles.hpp"
#include "vvariables/model_variables.hpp"

template <typename Dimensions>
inline Variables<Advection, Dimensions>
get_variables(
    const Parameters<Advection, Dimensions>& parameters,
    const Input& input) {
  Particles<Dimensions, FullF> particles {
      parameters.particle_parameters,
      "particles",
      parameters.time_parameters,
      input.output_path / "particles"};

  return {std::move(particles)};
}
