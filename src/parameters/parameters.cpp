#include "parameters.hpp"

#include <cassert>
#include <iostream>
#include <nlohmann/json.hpp>
#include <optional>

#include "io/input_parser.hpp"
#include "initial/space_initial.hpp"
#include "initial/velocity_initial.hpp"
#include "initial/scenarios/scenarios.hpp"

using json = nlohmann::json;

Parameters get_parameters(const json& data) {
  assert_top_level_keyword(data, "model");
  std::string model_name {data["model"]};
  Model model {string_to_model(model_name)};

  assert_top_level_keyword(data, "space_dimensions");
  int space_dimensions {data["space_dimensions"]};

  // If key is not in json then the model is assumed to have no velocity dimensions
  int velocity_dimensions {data.value("velocity_dimensions", 0)};

  Scenario scenario {get_scenario(data)};

  Space_Initial_Parameters space_initial_parameters {Space_Initial_Parameters()};

  // TODO: make correct initialization
  // if (scenario == Scenario::none) {
  //   space_initial_parameters {get_space_initial_parameters(data)};
  // } else {
  // }

  Parameters parameters {
      model,
      space_dimensions,
      velocity_dimensions
  };

  return parameters;
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