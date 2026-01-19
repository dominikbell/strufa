#pragma once

#include <random>

#include "functions/maxwellian.hpp"
#include "functions/sine.hpp"
#include "initial_condition/initial_condition.hpp"
#include "initial_condition/space_initial_condition.hpp"
#include "initial_condition/velocity_initial_condition.hpp"
#include "utilities/utilities.hpp"

template <typename T>
struct TypeDisplayer;

template <typename Particles>
void draw_markers(Particles& particles) {
  std::mt19937 gen(particles.seed);
  std::uniform_real_distribution<> real_distrib(0.0, 1.0);

  constexpr int dimensions {GetFirstType_t<decltype(particles)>::space_dimensions};

  for (int i = 0; i < dimensions; ++i) {
    for (double& pos : particles.positions[i]) {
      pos = real_distrib(gen);
    }
  }
}

template <typename Particles>
void draw_velocities(Particles& particles) {
  std::mt19937 gen(particles.seed);
  std::uniform_real_distribution<> real_distrib(0.0, 1.0);

  constexpr int dimensions {GetFirstType_t<decltype(particles)>::space_dimensions};

  for (int i = 0; i < dimensions; ++i) {
    for (double& vel : particles.velocities[i]) {
      vel = real_distrib(gen);
    }
  }
}

template <typename Particles>
void initialize_velocities(Particles& particles, const VelocityInitialVariant& velocity_initial_condition) {
  // Visit the variants of functions
  std::visit([&](const auto& function_variant) {
    // Visit the variants of dimensions of each function
    std::visit([&](const auto& dimension_variant) {
      constexpr int dimensions {GetFirstType_t<decltype(particles)>::velocity_dimensions};

      for (int i = 0; i < dimensions; ++i) {
        for (double& vel : particles.velocities[i]) {
          vel = initialize_with_function(dimension_variant, i, vel);
        }
      }
    },
               function_variant);
  },
             velocity_initial_condition);
}

template <typename Particles>
void initialize_weights(Particles& particles, const SpaceInitialVariant& space_initial_condition) {
  // Visit the variants of functions
  std::visit([&](const auto& function_variant) {
    // Visit the variants of dimensions of each function
    std::visit([&](const auto& dimensional_function) {
      // Get dimensions of initial condition and particles to make sure that they are the same
      using InitialDimensions = GetFirstInnerType_t<decltype(dimensional_function)>;
      constexpr int initial_dimensions {InitialDimensions::space_dimensions};
      using ParticleDimensions = GetFirstInnerType_t<decltype(particles)>;
      constexpr int particle_dimensions {ParticleDimensions::space_dimensions};

      if constexpr (initial_dimensions == 1 && particle_dimensions == 1) {
        for (long i = 0; i < particles.N_markers; ++i) {
          particles.weights[i] = initialize_with_function(dimensional_function, particles.positions[0][i]);
        }
      } else if constexpr (initial_dimensions == 2 && particle_dimensions == 2) {
        for (long i = 0; i < particles.N_markers; ++i) {
          particles.weights[i] = initialize_with_function(
              dimensional_function,
              particles.positions[0][i],
              particles.positions[1][i]);
        }
      } else if constexpr (initial_dimensions == 3 && particle_dimensions == 3) {
        for (long i = 0; i < particles.N_markers; ++i) {
          particles.weights[i] = initialize_with_function(
              dimensional_function,
              particles.positions[0][i],
              particles.positions[1][i],
              particles.positions[2][i]);
        }
      }
    },
               function_variant);
  },
             space_initial_condition);
}

template <typename Particles>
void initialize_particles(Particles& particles, const PhaseSpaceInitialCondition& initial_condition) {
  draw_markers(particles);
  initialize_weights(particles, initial_condition.space_initial_condition);
  draw_velocities(particles);
  initialize_velocities(particles, initial_condition.velocity_initial_condition);
}
