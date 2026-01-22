#pragma once

#include "models/base/models.hpp"
#include "parameters/model_parameters.hpp"
#include "vvariables/model_variables.hpp"

template <typename Dimensions>
inline Variables<Poisson, Dimensions>
get_variables(const Parameters<Poisson, Dimensions>& parameters) {
  return {};
}
