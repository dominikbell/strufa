#include "particle_initialization.hpp"

#include <nlohmann/json.hpp>
#include <random>

#include "functions/trigonometric.hpp"
#include "particles/particles.hpp"
#include "space_initial.hpp"
#include "velocity_initial.hpp"

using json = nlohmann::json;

void initialize_weights(

) {
  
}

void initialize_particles(
    Particles1D1V& particles,
    const Space_Initial& space_initial_condition,
    const Velocity_Initial& velocity_initial_condition) {
  std::mt19937 gen(particles.seed);
  std::uniform_real_distribution<> real_distrib(0.0, 1.0);

  // Initialize positions
  for (double& position : particles.positions_x) {
    position = real_distrib(gen);
  }

  // initialize_weights(particles, space_initial_condition);
}
