#pragma once

#include <optional>
#include <string>
#include <variant>

#include "utilities/utilities.hpp"

struct Advection {};
struct Poisson {};

using ModelVariant = std::variant<
    Advection,
    Poisson>;

inline std::optional<ModelVariant> string_to_model_optional(const std::string& str) {
  if (str == "Advection" || str == "advection") {
    return Advection {};
    } else if (str == "Poisson" || str == "poisson") {
      return Poisson {};
  } else {
    return std::nullopt;
  }
}

inline ModelVariant string_to_model(const std::string& str) {
  std::optional<ModelVariant> optional_model {string_to_model_optional(str)};

  if (optional_model) {
    return *optional_model;
  } else {
    exit_with_failure("model name", str);
  }
}
