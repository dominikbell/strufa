#include "parameters.hpp"

#include <cassert>
#include <iostream>
#include <nlohmann/json.hpp>
#include <optional>

#include "io/input_parser.hpp"
#include "scenarios/scenarios.hpp"

using json = nlohmann::json;

Parameters get_parameters(const json& data) {
  assert_top_level_keyword(data, "model");
  std::string model_name {data["model"]};
  assert_top_level_keyword(data, "space_dimensions");
  int space_dimensions {data["space_dimensions"]};

  bool contains_velocity_dimension {data.count("velocity_dimensions") == 1};

  Scenario scenario {get_scenario(data)};

  if (contains_velocity_dimension) {
    int velocity_dimensions {data["velocity_dimensions"]};
    Parameters parameters {
        model_name,
        space_dimensions,
        velocity_dimensions,
        scenario,
    };

    return parameters;

  } else {
    Parameters parameters {
        model_name,
        space_dimensions,
        0,
        scenario,
    };

    return parameters;
  }
}

Parameters_1D get_parameters_1d(const json& data) {
  assert_top_level_keyword(data, "domain");
  assert_second_level_keyword(data, "domain", "length");

  double domain_length {data["domain"]["length"]};

  Parameters_1D parameters_1d {domain_length};
  return parameters_1d;
}

TimeParameters get_time_parameters(const json& data) {
  assert_top_level_keyword(data, "time");
  assert_second_level_keyword(data, "time", "dt");
  assert_second_level_keyword(data, "time", "T_end");

  double dt {data["time"]["dt"]};
  double T_end {data["time"]["T_end"]};

  TimeParameters time_parameters {dt, T_end};
  return time_parameters;
}