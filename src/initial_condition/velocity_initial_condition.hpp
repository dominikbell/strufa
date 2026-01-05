#pragma once

#include <variant>

#include "functions/maxwellian.hpp"

enum class VelocityInitialEnum {
  maxwellian,
};

inline std::optional<VelocityInitialEnum> string_to_optional_velocity_initial_enum(const std::string& str) {
  if (str == "maxwellian") {
    return VelocityInitialEnum::maxwellian;
  } else {
    return std::nullopt;
  }
}

inline VelocityInitialEnum string_to_velocity_initial_enum(const std::string& str) {
  std::optional<VelocityInitialEnum> optional_velocity_initial {string_to_optional_velocity_initial_enum(str)};

  if (optional_velocity_initial) {
    return *optional_velocity_initial;
  } else {
    exit_with_failure("velocity initial condition", str);
  }
}

using VelocityInitialVariant = std::variant<MaxwellianVariant>;

VelocityInitialVariant get_velocity_initial_condition(int velocity_dimensions, const json& data);
