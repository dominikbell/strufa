#pragma once

#include <nlohmann/json.hpp>

#include "particles/particles.hpp"

using json = nlohmann::json;

void initialize_weights(Particles_1D1V& particles, const json& initial);
void initialize_particles(Particles_1D1V& particles, const json& initial);
