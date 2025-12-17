#pragma once

#include <nlohmann/json.hpp>
#include <string>

using json = nlohmann::json;

struct Parameters {
  const std::string model_name = "";
  const json initial;
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
  const int seed {0};
};