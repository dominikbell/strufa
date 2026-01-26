#pragma once

#include "io/input_parser.hpp"
#include "particles/particle_types.hpp"

struct ParticleParameters {
  const ParticleTypeVariant type {FullF {}};
  const long N_markers {0};
  const int seed {0};
};

ParticleParameters get_particle_parameters(const json& data);
