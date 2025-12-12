#pragma once

#include <string>

struct Parameters {
  const std::string model_name = "";
};

struct Parameters_1D : Parameters {};
struct Parameters_2D : Parameters {};
struct Parameters_3D : Parameters {};

struct TimeParameters : Parameters {
  const double dt {0.0};
  const double T_end {0.0};
};

struct ParticleParameters : Parameters {
  const long N_p {0};
};