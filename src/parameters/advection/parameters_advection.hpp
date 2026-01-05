#pragma once

#include <utility>

#include "io/input_parser.hpp"
#include "models/base/models.hpp"
#include "parameters/discretization/PIC_parameters.hpp"
#include "parameters/model_parameters.hpp"

template <>
struct Parameters<Advection, void> {
  const ParticleParameters particle_parameters;
};

using AdvectionParametersVariant = Parameters<Advection, void>;

AdvectionParametersVariant get_parameters_advection(std::pair<int, int> pair_dimensions, const json& data);
