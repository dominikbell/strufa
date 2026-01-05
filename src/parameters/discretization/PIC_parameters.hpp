#pragma once

#include <string>

#include "io/input_parser.hpp"
#include "particles/particle_types.hpp"

struct ParticleParameters {
  const ParticleTypeEnum type {ParticleTypeEnum::full_f};
  const long N_markers {0};
  const int seed {0};
};

ParticleParameters get_particle_parameters(const json& data);
