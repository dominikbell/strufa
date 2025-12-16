#pragma once

#include <vector>

#include "parameters.hpp"

struct Parameters_Advection_1D1V : Parameters_1D, TimeParameters, ParticleParameters
{
  const double mu {0.0};
  const double sigma {0.0};
  const double alpha {0.0};
  const double L {0.0};

  long N_markers {0};
};

struct Parameters_Advection_1D2V : Parameters_1D, TimeParameters, ParticleParameters
{
  const double mu {0.0};
  const double sigma {0.0};
  const double alpha {0.0};
  const double L {0.0};

  long N_markers {0};
};

Parameters_Advection_1D1V get_parameters_advection_1d1v();
Parameters_Advection_1D2V get_parameters_advection_1d2v();