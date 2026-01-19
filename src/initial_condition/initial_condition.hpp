#pragma once

#include <utilities/dimensions.hpp>
#include <utility>

#include "io/input_parser.hpp"
#include "space_initial_condition.hpp"
#include "velocity_initial_condition.hpp"

struct PhaseSpaceInitialCondition {
  SpaceInitialVariant space_initial_condition;
  VelocityInitialVariant velocity_initial_condition;
};

PhaseSpaceInitialCondition get_phase_space_initial_condition(
    std::pair<int, int> pair_dimensions,
    const json& init_data,
    const DomainParametersVariant& domain_parameters);
