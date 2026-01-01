#pragma once

#include <nlohmann/json.hpp>
#include <optional>
#include <string>
#include <variant>

#include "functions/trigonometric.hpp"
#include "utilities/utilities.hpp"

using json = nlohmann::json;

using Space_Initial_Type_1D = std::variant<Sine_1D, Cosine_1D>;
using Space_Initial_Type = std::variant<Space_Initial_Type_1D>;

enum class Space_Initial {
  constant,
  noise,
  sine,
  cosine,
};

inline std::optional<Space_Initial> string_to_optional_space_initial(const std::string& str) {
  if (str == "constant") {
    return Space_Initial::constant;
  } else if (str == "noise") {
    return Space_Initial::noise;
  } else if (str == "sine") {
    return Space_Initial::sine;
  } else if (str == "cosine") {
    return Space_Initial::cosine;
  } else {
    return std::nullopt;
  }
}

inline Space_Initial string_to_space_initial(const std::string& str) {
  std::optional<Space_Initial> optional_space_initial {string_to_optional_space_initial(str)};

  if (optional_space_initial) {
    return *optional_space_initial;
  } else {
    exit_with_failure("space initial condition", str);
  }
}

struct SpaceInitialParameters {
  const Space_Initial type {Space_Initial::constant};
  json initial;
};

Space_Initial get_space_initial_type(const json& data);
SpaceInitialParameters get_space_initial_parameters(const json& data);
