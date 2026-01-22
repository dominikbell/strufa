#pragma once

#include <iostream>

#include "models.hpp"
#include "vvariables/vvariables.hpp"

template <typename TDimensions>
void run(
    Variables<Advection, TDimensions>& variables,
    const Parameters<Advection, TDimensions>& parameters) {
  constexpr int dimensions {TDimensions::space_dimensions};

  const double dt {parameters.time_parameters.dt};
  const int N_timesteps {parameters.time_parameters.N_timesteps};

  for (int timestep = 0; timestep < N_timesteps; ++timestep) {
    std::cout << "Timestep number: " << timestep << '\n';
    for (int dim = 0; dim < dimensions; ++dim) {
      for (int i = 0; i < variables.particles.N_markers; ++i) {
        variables.particles.positions[dim][i] += dt * variables.particles.velocities[dim][i];
      }
    }
  }
}
