#pragma once

#include <nlohmann/json.hpp>
#include <optional>

#include "particles/particles.hpp"

using json = nlohmann::json;

enum class Initial_Condition {
  sine,
  cosine,
};

inline std::optional<Initial_Condition> string_to_initial(const std::string& str) {
  if (str == "sine") {
    return Initial_Condition::sine;
  } else if (str == "cosine") {
    return Initial_Condition::cosine;
  } else {
    return std::nullopt;
  }
}

void initialize_weights(Particles_1D1V& particles, const json& initial);
void initialize_particles(Particles_1D1V& particles, const json& initial);