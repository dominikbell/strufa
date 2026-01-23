#pragma once

#include <array>
#include <cmath>
#include <omp.h>

#include "models.hpp"
#include "parameters/parameters.hpp"
#include "vvariables/vvariables.hpp"

template <typename TDimensions>
void run(
    Variables<Advection, TDimensions>& variables,
    const Parameters<Advection, TDimensions>& parameters) {
  constexpr int dimensions {TDimensions::space_dimensions};

  const double dt {parameters.time_parameters.dt};
  const long N_markers {variables.particles.N_markers};
  const int N_timesteps {parameters.time_parameters.N_timesteps};
  const std::array<double, TDimensions::space_dimensions> domain_sizes {parameters.domain_parameters.domain_sizes};

#pragma omp parallel
  {
    for (int timestep = 0; timestep < N_timesteps; ++timestep) {
#pragma omp for
      for (int i = 0; i < N_markers; ++i) {
        for (int dim = 0; dim < dimensions; ++dim) {
          variables.particles.positions[dim][i] += dt * variables.particles.velocities[dim][i];
          variables.particles.positions[dim][i] = std::fmod(
              variables.particles.positions[dim][i], domain_sizes[dim]);
        }
      }
    }
  }
}
