#pragma once

#include <variant>

#include "functions/trigonometric.hpp"
#include "io/input_parser.hpp"
#include "utilities/dimensions.hpp"
#include "utilities/utilities.hpp"

template <typename Type>
struct SpaceInitialCondition;

using SpaceInitialVariant = std::variant<
    SpaceInitialCondition<SineVariant>,
    SpaceInitialCondition<CosineVariant> >;

template <typename Type>
inline SpaceInitialCondition<Type> get_space_initial_condition(const json& data) {
  // if constexpr
}

SpaceInitialVariant get_space_initial_condition(int space_dimensions, const json& data);
