#include "space_initial.hpp"

#include <nlohmann/json.hpp>
#include <optional>

#include "functions/trigonometric.hpp"
#include "scenarios/scenarios.hpp"
#include "particles/particles.hpp"

using json = nlohmann::json;

Space_Initial get_space_initial_type(const json& data) {
  Scenario scenario {get_scenario(data)};

  if (scenario == Scenario::none) {

  }
}

Space_Initial_Parameters get_space_initial_parameters(const json& data) {
  std::optional<Space_Initial> space_initial_condition {
  };
}

void initialize_weights(Particles_1D1V& particles, const Space_Initial& initial_condition) {
  switch (initial_condition) {
    case Space_Initial::sine: {
    };
    case Space_Initial::cosine: {
      // int wavenumber {initial["k"]};
      // double amplitude {initial["amplitude"]};
      // Cosine_1D cosine_1d {wavenumber, amplitude};
      // for (size_t k {0}; k < particles.N_markers; ++k) {
      //   particles.weights[k] = cosine(particles.positions_x[k], cosine_1d);
      // }
    };
  }
}

void initialize(Particles_1D1V& particles, const Sine_1D& initial_condition) {
  Sine_1D sine_1d {initial_condition.wavenumber, initial_condition.amplitude};
  for (size_t k {0}; k < particles.N_markers; ++k) {
    particles.weights[k] = sine(particles.positions_x[k], sine_1d);
  }
}

void initialize(Particles_1D1V& particles, const Cosine_1D& initial_condition) {
  Cosine_1D cosine_1d {initial_condition.wavenumber, initial_condition.amplitude};
  for (size_t k {0}; k < particles.N_markers; ++k) {
    particles.weights[k] = cosine(particles.positions_x[k], cosine_1d);
  }
}
