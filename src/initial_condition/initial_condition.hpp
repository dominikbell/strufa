#pragma once

#include <utility>
#include <variant>

#include "io/input_parser.hpp"
#include "space_initial_condition.hpp"
#include "velocity_initial_condition.hpp"
#include <utilities/dimensions.hpp>

struct PhaseSpaceInitialCondition {
  SpaceInitialVariant space_initial_condition;
  VelocityInitialVariant velocity_initial_condition;
};

using InitialConditionVariant = std::variant<
    SpaceInitialVariant,
    PhaseSpaceInitialCondition>;

InitialConditionVariant get_initial_condition(std::pair<int, int> pair_dimensions, const json& data);
