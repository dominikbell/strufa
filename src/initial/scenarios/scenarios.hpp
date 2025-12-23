#pragma once

#include <nlohmann/json.hpp>
#include <optional>
#include <string>

using json = nlohmann::json;

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
