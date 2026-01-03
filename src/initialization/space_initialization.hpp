#pragma once

#include <optional>
#include <string>
#include <variant>

#include "io/input_parser.hpp"
#include "functions/trigonometric.hpp"
#include "utilities/utilities.hpp"

enum class SpaceInitialEnum {
  constant,
  noise,
  sine,
  cosine,
};

inline std::optional<SpaceInitialEnum> string_to_optional_space_initial_enum(const std::string& str) {
  if (str == "constant") {
    return SpaceInitialEnum::constant;
  } else if (str == "noise") {
    return SpaceInitialEnum::noise;
  } else if (str == "sine") {
    return SpaceInitialEnum::sine;
  } else if (str == "cosine") {
    return SpaceInitialEnum::cosine;
  } else {
    return std::nullopt;
  }
}

inline SpaceInitialEnum string_to_space_initial_enum(const std::string& str) {
  std::optional<SpaceInitialEnum> optional_space_initial {string_to_optional_space_initial_enum(str)};

  if (optional_space_initial) {
    return *optional_space_initial;
  } else {
    exit_with_failure("space initial condition", str);
  }
}

struct SpaceInitialParameters {
  const SpaceInitialEnum type {SpaceInitialEnum::constant};
  json initial;
};

SpaceInitialEnum get_space_initial_type(const json& data);
SpaceInitialParameters get_space_initial_parameters(const json& data);
