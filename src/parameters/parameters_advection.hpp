#pragma once

#include <vector>

#include "parameters.hpp"

struct Parameters_Advection_1D1V : Parameters_1D, TimeParameters, ParticleParameters
{
  const double mu {0.0};
  const double sigma {0.0};
  const double alpha {0.0};
  const double L {0.0};

  std::vector<float> allocate_markers(long N_markers);
};