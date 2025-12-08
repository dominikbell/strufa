#pragma once

#include "parameters.hpp"

struct Parameters_Advection_1D1V : Parameters_1D
{
  double mu {0.0};
  double sigma {0.0};
  double alpha {0.0};
  double L {0.0};
};