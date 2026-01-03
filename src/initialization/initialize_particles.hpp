#pragma once

#include "initial_condition/initial_condition.hpp"

template <typename Particles>
void initialize_particles(Particles& particles, PhaseSpaceInitialCondition initial_condition);
