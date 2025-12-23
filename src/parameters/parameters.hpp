#pragma once

#include <nlohmann/json.hpp>
#include <string>

#include "initial/space_initial.hpp"
#include "initial/velocity_initial.hpp"
#include "models/base/models.hpp"

using json = nlohmann::json;

struct Parameters {
  const Model model;
  const int space_dimensions;
  const int velocity_dimensions;

  Parameters(
      Model model_i,
      int space_dimensions_i,
      int velocity_dimensions_i = 0)
      : model {model_i},
        space_dimensions {space_dimensions_i},
        velocity_dimensions {velocity_dimensions_i} {}
};

struct Parameters_1D {
  const double domain_length;

  Parameters_1D(
      double domain_length_i)
      : domain_length {domain_length_i} {}
};

struct TimeParameters {
  const double dt;
  const double T_end;

  TimeParameters(double dt_i, double T_end_i) : dt {dt_i}, T_end {T_end_i} {}
};

Parameters get_parameters(const json& data);
Parameters_1D get_parameters_1d(const json& data);
TimeParameters get_time_parameters(const json& data);
