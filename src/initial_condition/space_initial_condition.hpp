#pragma once

#include <variant>

#include "functions/sine.hpp"
#include "functions/cosine.hpp"
#include "io/input_parser.hpp"

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

using SpaceInitialVariant = std::variant<
    SineVariant,
    CosineVariant >;

SpaceInitialVariant get_space_initial_condition(const json& data, const DomainParametersVariant& domain_parameters);
