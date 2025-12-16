#include <random>

#include "particles.hpp"

void sample_particles(Particles_1D1V& particles) {
  std::mt19937 gen(particles.seed);
  std::uniform_real_distribution<> real_distrib(0.0, 1.0);

  for (double& weight : particles.weights) {
    weight = real_distrib(gen);
  }
}