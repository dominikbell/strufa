#pragma once

#include <string>

struct Parameters {
  const std::string model_name = "";
};

struct Parameters_1D {
  const double domain_length {0.0};
};
struct Parameters_2D {};
struct Parameters_3D {};

struct TimeParameters {
  const double dt {0.0};
  const double T_end {0.0};
};

struct ParticleParameters {
  const long N_markers {0};
};