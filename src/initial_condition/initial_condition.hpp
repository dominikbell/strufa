#pragma once

#include <utilities/dimensions.hpp>

#include "io/input_parser.hpp"
#include "space_initial_condition.hpp"
#include "utilities/utilities.hpp"
#include "velocity_initial_condition.hpp"

struct PhaseSpaceInitialCondition {
  SpaceInitialVariant space_initial_condition;
  VelocityInitialVariant velocity_initial_condition;
};

template <typename TDimensions>
PhaseSpaceInitialCondition get_phase_space_initial_condition(
    const json& init_data,
    const DomainParameters<typename TDimensions::SpaceOnly>& domain_parameters) {

      bool is_scenario {init_data.count("scenario") == 1};

      if (is_scenario) {
        exit_with_failure("Scenarios are not implemented yet.");
        // return get_initial_condition_from_scenario(pair_dimensions, data);
      } else {
        SpaceInitialVariant space_initial {get_space_initial_condition(init_data["space"], domain_parameters)};
        VelocityInitialVariant velocity_initial {get_velocity_initial_condition<typename TDimensions::VelocityOnly>(init_data["velocity"])};

        PhaseSpaceInitialCondition phase_space_initial {space_initial, velocity_initial};

        return phase_space_initial;
      }
    }
