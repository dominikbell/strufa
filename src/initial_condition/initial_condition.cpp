#include "initial_condition.hpp"

InitialConditionVariant get_initial_condition(std::pair<int, int> pair_dimensions, const json& data) {
  bool is_scenario {data.count("scenario") == 1};

  if (is_scenario) {
    // return get_initial_condition_from_scenario(pair_dimensions, data);
  } else {
    if (pair_dimensions.second == 0) {
      // return get_space_initial_condition(pair_dimensions.first, data);
    }
  }
}
