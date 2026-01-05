#pragma once

#include <optional>
#include <string>

#include "utilities/utilities.hpp"

struct FullF {};
struct DeltaF {};
struct DirectDeltaF {};
struct ControlVariate {};

enum class ParticleTypeEnum {
  full_f,
  delta_f,
  direct_delta_f,
  control_variate,
};

inline std::optional<ParticleTypeEnum> string_to_optional_particle_type_enum(const std::string& str) {
  if (str == "full_f") {
    return ParticleTypeEnum::full_f;
  } else if (str == "delta_f") {
    return ParticleTypeEnum::delta_f;
  } else if (str == "direct_delta_f") {
    return ParticleTypeEnum::direct_delta_f;
  } else if (str == "control_variate") {
    return ParticleTypeEnum::control_variate;
  } else {
    return std::nullopt;
  }
}

inline ParticleTypeEnum string_to_particle_type_enum(const std::string& str) {
  std::optional<ParticleTypeEnum> optional_particle_type {string_to_optional_particle_type_enum(str)};

  if (optional_particle_type) {
    return *optional_particle_type;
  } else {
    exit_with_failure("particle type", str);
  }
}
