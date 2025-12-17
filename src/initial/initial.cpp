#include "initial.hpp"

#include <functional>
#include <nlohmann/json.hpp>
#include <random>

#include "functions/trigonometric.hpp"
#include "particles/particles.hpp"

using json = nlohmann::json;

void initialize_weights(Particles_1D1V& particles, const json& initial) {
  const std::string initial_type {initial["type"]};
  std::optional<Initial_Condition> initial_condition {string_to_initial(initial_type)};

  if (initial_condition) {
    switch (*initial_condition) {
      case Initial_Condition::sine: {
        int wavenumber {initial["k"]};
        double amplitude {initial["amplitude"]};
        Sine_1D sine_1d {wavenumber, amplitude};
        for (size_t k {0}; k < particles.N_markers; ++k) {
          particles.weights[k] = sine(particles.positions_x[k], sine_1d);
        }
      };
      case Initial_Condition::cosine: {
        int wavenumber {initial["k"]};
        double amplitude {initial["amplitude"]};
        Cosine_1D cosine_1d {wavenumber, amplitude};
        for (size_t k {0}; k < particles.N_markers; ++k) {
          particles.weights[k] = cosine(particles.positions_x[k], cosine_1d);
        }
      };
    }
  }
}

void initialize_particles(Particles_1D1V& particles, const json& initial) {
  std::mt19937 gen(particles.seed);
  std::uniform_real_distribution<> real_distrib(0.0, 1.0);

  // Initialize positions
  for (double& position : particles.positions_x) {
    position = real_distrib(gen);
  }

  initialize_weights(particles, initial);
}