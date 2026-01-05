#include "initial_condition.hpp"

InitialConditionVariant get_initial_condition(std::pair<int, int> pair_dimensions, const json& data) {
  bool is_scenario {data.count("scenario") == 1};

  if (is_scenario) {
    // return get_initial_condition_from_scenario(pair_dimensions, data);
  } else {
    if (pair_dimensions.second == 0) {
      return get_space_initial_condition(pair_dimensions.first, data["space"]);
    } else {
      SpaceInitialVariant space_initial {get_space_initial_condition(pair_dimensions.first, data["space"])};
      VelocityInitialVariant velocity_initial {get_velocity_initial_condition(pair_dimensions.second, data["velocity"])};

      PhaseSpaceInitialCondition phase_space_initial {space_initial, velocity_initial};

      return phase_space_initial;
    }
  }
}
