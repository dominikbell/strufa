#pragma once

#include <optional>
#include <string>

#include "initial_condition/initial_condition.hpp"
#include "io/input_parser.hpp"

enum class Scenario {
  none,
  weak_landau,
  strong_landau,
  bernstein,
  two_stream,
  bump_on_tail,
};

inline Scenario string_to_scenario(const std::string& str) {
  if (str == "weak_landau") {
    return Scenario::weak_landau;
  } else if (str == "strong_landau") {
    return Scenario::strong_landau;
  } else if (str == "bernstein") {
    return Scenario::bernstein;
  } else if (str == "two_stream") {
    return Scenario::two_stream;
  } else if (str == "bump_on_tail") {
    return Scenario::bump_on_tail;
  } else {
    return Scenario::none;
  }
}

Scenario get_scenario(const json& data);

// InitialConditionVariant get_initial_condition_from_scenario(std::pair<int, int> pair_dimensions, const json& data);
