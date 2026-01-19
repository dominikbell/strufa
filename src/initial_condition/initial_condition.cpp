#include "initial_condition.hpp"
#include "parameters/domain_parameters.hpp"

PhaseSpaceInitialCondition get_phase_space_initial_condition(
    std::pair<int, int> pair_dimensions,
    const json& init_data,
    const DomainParametersVariant& domain_parameters) {
  bool is_scenario {init_data.count("scenario") == 1};

  if (is_scenario) {
    // return get_initial_condition_from_scenario(pair_dimensions, data);
  } else {
    SpaceInitialVariant space_initial {get_space_initial_condition(init_data["space"], domain_parameters)};
    VelocityInitialVariant velocity_initial {get_velocity_initial_condition(pair_dimensions.second, init_data["velocity"])};

    PhaseSpaceInitialCondition phase_space_initial {space_initial, velocity_initial};

    return phase_space_initial;
  }
}
