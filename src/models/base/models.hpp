#pragma once

#include <optional>
#include <string>

#include "utilities/utilities.hpp"

enum class Model {
  advection,
  poisson,
};

inline Model string_to_model(const std::string& str) {
  if (str == "Advection") {
    return Model::advection;
  } else if (str == "Poisson") {
    return Model::poisson;
  } else {
    exit_with_failure("model name", str);
  }
}

inline std::string model_to_string(const Model& model) {
  switch (model) {
    case Model::advection: {
      return "Advection";
    }
    case Model::poisson: {
      return "Poisson";
    }
  }
}