#pragma once

#include <optional>
#include <string>
#include <variant>

#include "utilities/utilities.hpp"

struct Advection {};
struct Poisson {};

using ModelVariant = std::variant<Advection, Poisson>;

enum class ModelEnum {
  advection,
  poisson,
};

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

inline std::optional<ModelEnum> string_to_model_enum_optional(const std::string& str) {
  if (str == "Advection" || str == "advection") {
    return ModelEnum::advection;
  } else if (str == "Poisson" || str == "poisson") {
    return ModelEnum::poisson;
  } else {
    return std::nullopt;
  }
}

inline ModelEnum string_to_model_enum(const std::string& str) {
  std::optional<ModelEnum> optional_model_enum {string_to_model_enum_optional(str)};

  if (optional_model_enum) {
    return *optional_model_enum;
  } else {
    exit_with_failure("model name", str);
  }
}

inline std::string model_enum_to_string(const ModelEnum& model) {
  switch (model) {
    case (ModelEnum::advection): return "Advection";
    case (ModelEnum::poisson): return "Poisson";
  }
}
