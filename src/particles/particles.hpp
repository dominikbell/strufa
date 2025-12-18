#pragma once

#include <nlohmann/json.hpp>
#include <optional>
#include <vector>

#include "background/background.hpp"

using json = nlohmann::json;

enum class Particle_Type {
  full_f,
  delta_f,
  direct_delta_f,
  control_variate,
};

inline std::optional<Particle_Type> string_to_particle_type(const std::string& str) {
  if (str == "full_f") {
    return Particle_Type::full_f;
  } else if (str == "delta_f") {
    return Particle_Type::delta_f;
  } else if (str == "direct_delta_f") {
    return Particle_Type::direct_delta_f;
  } else if (str == "control_variate") {
    return Particle_Type::control_variate;
  } else {
    return std::nullopt;
  }
}

struct ParticleParameters {
  const Particle_Type type {Particle_Type::full_f};
  const Background background {Background::none};
  const long N_markers {0};
  const int seed {0};
};

struct Particles_1D1V {
  const Particle_Type type {Particle_Type::full_f};
  const Background background {Background::none};
  const long N_markers {0};
  const int seed {0};
  std::vector<double> weights;
  std::vector<double> positions_x;
  std::vector<double> velocities_x;

  Particles_1D1V(ParticleParameters particle_parameters) : type {particle_parameters.type},
                                                           N_markers {particle_parameters.N_markers},
                                                           seed {particle_parameters.seed},
                                                           weights(particle_parameters.N_markers),
                                                           positions_x(particle_parameters.N_markers),
                                                           velocities_x(particle_parameters.N_markers) {}
};

ParticleParameters get_particle_parameters(const json& data);
