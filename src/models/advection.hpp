#pragma once

#include <omp.h>

#include <cstddef>
#include <array>
#include <cmath>

#include "models.hpp"
#include "parameters/parameters.hpp"
#include "particles/particles.hpp"
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

  // Save markers before doing anything
  variables.particles.save_markers(0);

#pragma omp parallel
  {
  // Saving happens after one step so timestep is shifted by one
    for (size_t timestep = 1; timestep <= N_timesteps; ++timestep) {
      for (size_t dim = 0; dim < dimensions; ++dim) {
#pragma omp for
        for (size_t i = 0; i < N_markers; ++i) {
          variables.particles.positions[dim][i] += dt * variables.particles.velocities[dim][i];
          variables.particles.positions[dim][i] = std::fmod(
              variables.particles.positions[dim][i], domain_sizes[dim]);
        }
      }
      // Only one thread should write to the io
#pragma omp master
      {
        variables.particles.save_markers(timestep);
      }
#pragma omp barrier
    }
  }
}
