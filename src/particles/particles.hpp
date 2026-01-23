#pragma once

#include <array>
#include <string>
#include <vector>

#include "parameters/discretization/PIC_parameters.hpp"
#include "particle_types.hpp"

template <typename Dimensions, typename ParticleType>
struct Particles;

// ==========================================================================
// Templated trickery to check if an object is of a particles templated class
template <typename T>
struct is_particles : std::false_type {};

template <typename Dimensions, typename ParticleType>
struct is_particles<Particles<Dimensions, ParticleType>> : std::true_type {};

template <typename T>
inline constexpr bool is_particles_v = is_particles<T>::value;
// ==========================================================================

template <typename Dimensions>
struct Particles<Dimensions, FullF> {
  const long N_markers {0};
  const int seed {0};
  const std::string name {""};
  std::vector<double> weights;
  std::array<std::vector<double>, Dimensions::space_dimensions> positions;
  std::array<std::vector<double>, Dimensions::velocity_dimensions> velocities;

  Particles(
      const ParticleParameters& particle_parameters,
      const std::string& name_i)
      : N_markers {particle_parameters.N_markers},
        seed {particle_parameters.seed},
        name {name_i} {
    weights.resize(N_markers);
    for (auto& position_vector : positions)
      position_vector.resize(N_markers);
    for (auto& velocity_vector : velocities)
      velocity_vector.resize(N_markers);
  }
};
