#pragma once

#include <vector>

#include "functions/maxwellian.hpp"
#include "io/input_parser.hpp"
#include "parameters.hpp"
#include "particles/particles.hpp"

struct Parameters_Advection : Parameters, TimeParameters, ParticleParameters {
  Parameters_Advection(
      Parameters& parameters_i,
      TimeParameters time_parameters_i,
      ParticleParameters& particle_parameters_i) : Parameters(parameters_i),
                                                   TimeParameters(time_parameters_i),
                                                   ParticleParameters(particle_parameters_i) {}
};

struct Parameters_Advection_1D1V : Parameters_Advection, Parameters_1D {
  Parameters_Advection_1D1V(
      Parameters_Advection& parameters_advection_i,
      Parameters_1D& parameters_1d_i) : Parameters_Advection(parameters_advection_i),
                                        Parameters_1D(parameters_1d_i) {}
};

Parameters_Advection_1D1V get_parameters_advection_1d1v(const Input& input);
