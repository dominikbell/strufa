#pragma once

#include <vector>

#include "functions/maxwellian.hpp"
#include "io/input_parser.hpp"
#include "parameters.hpp"

struct Parameters_Advection : Parameters, TimeParameters, ParticleParameters {};

struct Parameters_Advection_1D1V : Parameters_Advection, Parameters_1D {
  Maxwellian maxwellian {};
};

// struct Parameters_Advection_1D2V : Parameters_Advection, Parameters_1D {
//   Maxwellian maxwellian_x {};
//   Maxwellian maxwellian_y {};
//   const double amplitude {0.0};
// };

Parameters_Advection_1D1V get_parameters_advection_1d1v(const Input& input);
// Parameters_Advection_1D2V get_parameters_advection_1d2v(const Input& input);