#pragma once

#include <optional>
#include <string>
#include <variant>

#include "utilities/utilities.hpp"

struct FullF {};
struct DeltaF {};
struct DirectDeltaF {};
struct ControlVariate {};

using ParticleTypeVariant = std::variant<
    FullF,
    DeltaF,
    DirectDeltaF,
    ControlVariate>;

inline std::optional<ParticleTypeVariant> string_to_optional_particle_type(const std::string& str) {
  if (str == "full_f") {
    return FullF {};
  } else if (str == "delta_f") {
    return DeltaF {};
  } else if (str == "direct_delta_f") {
    return DirectDeltaF {};
  } else if (str == "control_variate") {
    return ControlVariate {};
  } else {
    return std::nullopt;
  }
}

inline ParticleTypeVariant string_to_particle_type(const std::string& str) {
  std::optional<ParticleTypeVariant> optional_particle_type {string_to_optional_particle_type(str)};

  if (optional_particle_type) {
    return *optional_particle_type;
  } else {
    exit_with_failure("particle type", str);
  }
}
