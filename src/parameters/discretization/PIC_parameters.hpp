#pragma once

#include <string>

#include "io/input_parser.hpp"
#include "utilities/utilities.hpp"

enum class ParticleType {
  full_f,
  delta_f,
  direct_delta_f,
  control_variate,
};

inline std::optional<ParticleType> string_to_optional_particle_type(const std::string& str) {
  if (str == "full_f") {
    return ParticleType::full_f;
  } else if (str == "delta_f") {
    return ParticleType::delta_f;
  } else if (str == "direct_delta_f") {
    return ParticleType::direct_delta_f;
  } else if (str == "control_variate") {
    return ParticleType::control_variate;
  } else {
    return std::nullopt;
  }
}

inline ParticleType string_to_particle_type(const std::string& str) {
  std::optional<ParticleType> optional_particle_type {string_to_optional_particle_type(str)};

  if (optional_particle_type) {
    return *optional_particle_type;
  } else {
    exit_with_failure("particle type", str);
  }
}

struct ParticleParameters {
  const ParticleType type {ParticleType::full_f};
  const long N_markers {0};
  const int seed {0};
};

ParticleParameters get_particle_parameters(const json& data);
