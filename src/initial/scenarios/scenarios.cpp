#include "scenarios.hpp"

#include <iostream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

Scenario get_scenario(const json& data) {
  bool contains_scenario {data.count("scenario") == 1};

  if (contains_scenario) {
    std::string scenario_name {data["scenario"]};
    std::optional<Scenario> scenario {string_to_scenario(scenario_name)};

    if (scenario) {
      return *scenario;
    } else {
      std::cerr << "Scenario name '" << scenario_name << "' is not a valid choice!\n";
      assert(scenario && "Invalid scenario entered, see line above.\n");
    }
  } else {
    return Scenario::none;
  }
}
