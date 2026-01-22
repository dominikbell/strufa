#include "scenario.hpp"

#include "io/input_parser.hpp"
#include "utilities/utilities.hpp"

Scenario get_scenario(const json& data) {
  bool contains_scenario {data.count("scenario") == 1};

  if (contains_scenario) {
    std::string scenario_name {data["scenario"]};
    std::optional<Scenario> scenario {string_to_scenario(scenario_name)};

    if (scenario) {
      return *scenario;
    } else {
      exit_with_failure("scenario name", scenario_name);
    }
  } else {
    return Scenario::none;
  }
}
