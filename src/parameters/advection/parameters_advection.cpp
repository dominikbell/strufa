#include "parameters_advection.hpp"

AdvectionParametersVariant get_parameters_advection(
    std::pair<int, int> pair_dimensions,
    const json& data) {
  ParticleParameters particle_parameters {get_particle_parameters(data)};

  return {particle_parameters};
}
