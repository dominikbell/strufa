#pragma once

#include <cmath>

#include "io/input_parser.hpp"

struct TimeParameters {
  const double dt;
  const double T_end;
  int N_timesteps;

  TimeParameters(
    double dt_i,
    double T_end_i
  ) : dt (dt_i),
  T_end (T_end_i),
  N_timesteps (std::ceil(T_end_i / dt)) {}
};

TimeParameters get_time_parameters(const json& data);
