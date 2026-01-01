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

template <>
struct Particles<D1V1, FullF> {
  const long N_markers {0};
  const int seed {0};
  std::vector<double> weights;
  std::vector<double> positions_x;
  std::vector<double> velocities_x;

  Particles(ParticleParameters particle_parameters)
      : N_markers {particle_parameters.N_markers},
        seed {particle_parameters.seed},
        weights(particle_parameters.N_markers),
        positions_x(particle_parameters.N_markers),
        velocities_x(particle_parameters.N_markers) {}
};

template <>
struct Particles<D1V2, FullF> {
  const long N_markers {0};
  const int seed {0};
  std::vector<double> weights;
  std::vector<double> positions_x;
  std::vector<double> velocities_x;
  std::vector<double> velocities_y;

  Particles(ParticleParameters particle_parameters)
      : N_markers {particle_parameters.N_markers},
        seed {particle_parameters.seed},
        weights(particle_parameters.N_markers),
        positions_x(particle_parameters.N_markers),
        velocities_x(particle_parameters.N_markers),
        velocities_y(particle_parameters.N_markers) {}
};

template <>
struct Particles<D1V3, FullF> {
  const long N_markers {0};
  const int seed {0};
  std::vector<double> weights;
  std::vector<double> positions_x;
  std::vector<double> velocities_x;
  std::vector<double> velocities_y;
  std::vector<double> velocities_z;

  Particles(ParticleParameters particle_parameters)
      : N_markers {particle_parameters.N_markers},
        seed {particle_parameters.seed},
        weights(particle_parameters.N_markers),
        positions_x(particle_parameters.N_markers),
        velocities_x(particle_parameters.N_markers),
        velocities_y(particle_parameters.N_markers),
        velocities_z(particle_parameters.N_markers) {}
};

template <>
struct Particles<D2V2, FullF> {
  const long N_markers {0};
  const int seed {0};
  std::vector<double> weights;
  std::vector<double> positions_x;
  std::vector<double> positions_y;
  std::vector<double> velocities_x;
  std::vector<double> velocities_y;

  Particles(ParticleParameters particle_parameters)
      : N_markers {particle_parameters.N_markers},
        seed {particle_parameters.seed},
        weights(particle_parameters.N_markers),
        positions_x(particle_parameters.N_markers),
        positions_y(particle_parameters.N_markers),
        velocities_x(particle_parameters.N_markers),
        velocities_y(particle_parameters.N_markers) {}
};

template <>
struct Particles<D2V3, FullF> {
  const long N_markers {0};
  const int seed {0};
  std::vector<double> weights;
  std::vector<double> positions_x;
  std::vector<double> positions_y;
  std::vector<double> velocities_x;
  std::vector<double> velocities_y;
  std::vector<double> velocities_z;

  Particles(ParticleParameters particle_parameters)
      : N_markers {particle_parameters.N_markers},
        seed {particle_parameters.seed},
        weights(particle_parameters.N_markers),
        positions_x(particle_parameters.N_markers),
        positions_y(particle_parameters.N_markers),
        velocities_x(particle_parameters.N_markers),
        velocities_y(particle_parameters.N_markers),
        velocities_z(particle_parameters.N_markers) {}
};

template <>
struct Particles<D3V3, FullF> {
  const long N_markers {0};
  const int seed {0};
  std::vector<double> weights;
  std::vector<double> positions_x;
  std::vector<double> positions_y;
  std::vector<double> positions_z;
  std::vector<double> velocities_x;
  std::vector<double> velocities_y;
  std::vector<double> velocities_z;

  Particles(ParticleParameters particle_parameters)
      : N_markers {particle_parameters.N_markers},
        seed {particle_parameters.seed},
        weights(particle_parameters.N_markers),
        positions_x(particle_parameters.N_markers),
        positions_y(particle_parameters.N_markers),
        positions_z(particle_parameters.N_markers),
        velocities_x(particle_parameters.N_markers),
        velocities_y(particle_parameters.N_markers),
        velocities_z(particle_parameters.N_markers) {}
};
