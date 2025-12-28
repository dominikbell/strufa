#pragma once

#include <nlohmann/json.hpp>

#include "particles/particles.hpp"

using json = nlohmann::json;

void initialize_weights(Particles1D1V& particles, const json& initial);
void initialize_particles(Particles1D1V& particles, const json& initial);
