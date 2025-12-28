#pragma once

#include <nlohmann/json.hpp>
#include <optional>
#include <string>
#include <variant>
#include <vector>

#include "background/background.hpp"
#include "utilities/utilities.hpp"

using json = nlohmann::json;

enum class Particle_Method {
  full_f,
  delta_f,
  direct_delta_f,
  control_variate,
};

inline std::string particle_method_to_string(Particle_Method particle_type) {
  switch (particle_type) {
    case Particle_Method::full_f: {
      return "full_f";
    }
    case Particle_Method::delta_f: {
      return "delta_f";
    }
    case Particle_Method::direct_delta_f: {
      return "direct_delta_f";
    }
    case Particle_Method::control_variate: {
      return "control_variate";
    }
  }
}

inline std::optional<Particle_Method> string_to_optional_particle_method(const std::string& str) {
  if (str == "full_f") {
    return Particle_Method::full_f;
  } else if (str == "delta_f") {
    return Particle_Method::delta_f;
  } else if (str == "direct_delta_f") {
    return Particle_Method::direct_delta_f;
  } else if (str == "control_variate") {
    return Particle_Method::control_variate;
  } else {
    return std::nullopt;
  }
}

inline Particle_Method string_to_particle_method(const std::string& str) {
  std::optional<Particle_Method> optional_particle_type {string_to_optional_particle_method(str)};

  if (optional_particle_type) {
    return *optional_particle_type;
  } else {
    exit_with_failure("particle type", str);
  }
}

struct ParticleParameters {
  const Particle_Method type {Particle_Method::full_f};
  const long N_markers {0};
  const int seed {0};
};

struct Particles1D1V {
  const Particle_Method type {Particle_Method::full_f};
  const long N_markers {0};
  const int seed {0};
  std::vector<double> weights;
  std::vector<double> positions_x;
  std::vector<double> velocities_x;

  Particles1D1V(ParticleParameters particle_parameters)
      : type {particle_parameters.type},
        N_markers {particle_parameters.N_markers},
        seed {particle_parameters.seed},
        weights(particle_parameters.N_markers),
        positions_x(particle_parameters.N_markers),
        velocities_x(particle_parameters.N_markers) {}
};

struct Particles_1D2V {
  const Particle_Method type {Particle_Method::full_f};
  const long N_markers {0};
  const int seed {0};
  std::vector<double> weights;
  std::vector<double> positions_x;
  std::vector<double> velocities_x;
  std::vector<double> velocities_y;

  Particles_1D2V(ParticleParameters particle_parameters)
      : type {particle_parameters.type},
        N_markers {particle_parameters.N_markers},
        seed {particle_parameters.seed},
        weights(particle_parameters.N_markers),
        positions_x(particle_parameters.N_markers),
        velocities_x(particle_parameters.N_markers),
        velocities_y(particle_parameters.N_markers) {}
};

using Particle_Type = std::variant<Particles1D1V, Particles_1D2V>;

ParticleParameters get_particle_parameters(const json& data);
