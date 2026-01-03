#pragma once

#include <utility>
#include <variant>

#include "initial_condition/scenario/scenario.hpp"
#include "io/input_parser.hpp"
#include "space_initial_condition.hpp"
#include "velocity_initial_condition.hpp"

struct PhaseSpaceInitialCondition {
  SpaceInitialVariant space_initial_condition;
  VelocityInitialVariant velocity_initial_condition;
};

using InitialConditionVariant = std::variant<
    SpaceInitialVariant,
    PhaseSpaceInitialCondition>;

InitialConditionVariant get_initial_condition(std::pair<int, int> pair_dimensions, const json& data);
