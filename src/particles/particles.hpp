#pragma once

#include <string>
#include <variant>
#include <vector>

#include "background/background.hpp"
#include "io/input_parser.hpp"
#include "parameters/discretization/PIC_parameters.hpp"
#include "particle_types.hpp"
#include "utilities/dimensions.hpp"
#include "utilities/utilities.hpp"

template <typename Dimensions, typename ParticleType>
struct Particles;

// ==========================================================================
// Templated trickery to check if somthing is of a particles templated class
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
  std::vector<double> positions[Dimensions::space_dimensions];
  std::vector<double> velocities[Dimensions::velocity_dimensions];

  Particles(
      const ParticleParameters& particle_parameters,
      const std::string& name_i)
      : N_markers {particle_parameters.N_markers},
        seed {particle_parameters.seed},
        name {name_i} {
    for (int i = 0; i < Dimensions::space_dimensions; ++i)
      positions[i].resize(N_markers);
    for (int i = 0; i < Dimensions::velocity_dimensions; ++i)
      velocities[i].resize(N_markers);
  }
};
