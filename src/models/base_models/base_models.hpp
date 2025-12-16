#pragma once

#include <optional>
#include <string>

enum class Model {
  advection,
  poisson,
};

inline std::optional<Model> string_to_model(std::string& str) {
  if (str == "Advection") {
    return Model::advection;
  } else if (str == "Poisson") {
    return Model::poisson;
  } else {
    return std::nullopt;
  }
}

inline std::string model_to_string(const Model& model) {
  switch (model) {
    case Model::advection: {return "Advection";}
    case Model::poisson: {return "Poisson";}
  }
}