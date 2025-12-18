#pragma once

#include <nlohmann/json.hpp>
#include <string>

#include "scenarios/scenarios.hpp"

using json = nlohmann::json;

struct Parameters {
  const std::string model_name {""};
  const int space_dimensions {0};
  const int velocity_dimensions {0};
  const Scenario scenario {Scenario::none};

  Parameters(
      std::string model_name_i,
      int space_dimensions_i,
      int velocity_dimensions_i,
      Scenario scenario_i) : model_name {model_name_i},
                             space_dimensions {space_dimensions_i},
                             velocity_dimensions {velocity_dimensions_i},
                             scenario {scenario_i} {}
};

struct Parameters_1D {
  const double domain_length {0.0};

  Parameters_1D(
      double domain_length_i) : domain_length {domain_length_i} {}
};

struct TimeParameters {
  const double dt {0.0};
  const double T_end {0.0};

  TimeParameters(
      double dt_i,
      double T_end_i) : dt {dt_i}, T_end {T_end_i} {}
};

Parameters get_parameters(const json& data);
Parameters_1D get_parameters_1d(const json& data);
TimeParameters get_time_parameters(const json& data);
