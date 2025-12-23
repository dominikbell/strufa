#pragma once

#include <cassert>
#include <iostream>
#include <nlohmann/json.hpp>
#include <optional>
#include <string>

#include "utilities/utilities.hpp"

using json = nlohmann::json;

enum class Velocity_Initial {
  none,
  maxwellian,
};

inline std::optional<Velocity_Initial> string_to_optional_velocity_initial(const std::string& str) {
  if (str == "") {
    return Velocity_Initial::none;
  } else if (str == "maxwellian") {
    return Velocity_Initial::maxwellian;
  } else {
    return std::nullopt;
  }
}

inline Velocity_Initial string_to_velocity_initial(const std::string& str) {
  std::optional<Velocity_Initial> optional_velocity_initial {string_to_optional_velocity_initial(str)};
  
  if (optional_velocity_initial) {
    return *optional_velocity_initial;
  } else {
    exit_with_failure("velocity initial condition", str);
  }
}

struct Velocity_Initial_Parameters {
  const Velocity_Initial type {Velocity_Initial::none};
  json initial;
};
