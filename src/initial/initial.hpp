#pragma once

#include <nlohmann/json.hpp>
#include <optional>

#include "particles/particles.hpp"

using json = nlohmann::json;

enum class Velocity_Initial_Condition {
  maxwellian,
};

inline std::optional<Velocity_Initial_Condition> string_to_velocity_initial(const std::string& str) {
  if (str == "maxwellian") {
    return Velocity_Initial_Condition::maxwellian;
  } else {
    return std::nullopt;
  }
}

enum class Space_Initial_Condition {
  noise,
  sine,
  cosine,
};

inline std::optional<Space_Initial_Condition> string_to_space_initial(const std::string& str) {
  if (str == "noise") {
    return Space_Initial_Condition::noise;
  } else if (str == "sine") {
    return Space_Initial_Condition::sine;
  } else if (str == "cosine") {
    return Space_Initial_Condition::cosine;
  } else {
    return std::nullopt;
  }
}

void initialize_weights(Particles_1D1V& particles, const json& initial);
void initialize_particles(Particles_1D1V& particles, const json& initial);