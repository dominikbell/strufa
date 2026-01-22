#pragma once

#include <variant>

#include "functions/cosine.hpp"
#include "functions/sine.hpp"
#include "io/input_parser.hpp"
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

using SpaceInitialVariant = std::variant<
    SineVariant,
    CosineVariant>;

template <typename TDimensions>
SpaceInitialVariant get_space_initial_condition(
    const json& initial_data,
    const DomainParameters<TDimensions>& domain_parameters) {
  if (initial_data.count("type") == 1) {
    SpaceInitialEnum space_initial {string_to_space_initial_enum(initial_data["type"])};

    switch (space_initial) {
      case (SpaceInitialEnum::sine):
        return get_sine(initial_data, domain_parameters);
      case (SpaceInitialEnum::cosine):
        return get_cosine(initial_data, domain_parameters);
      default:
        exit_with_failure("Space initial condition not implemented.");
    }

  } else {
    exit_with_failure("Initialization in space must include keyword 'type'!\n");
  }
}
