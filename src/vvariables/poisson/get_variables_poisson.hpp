#pragma once

#include "models/models.hpp"
#include "parameters/model_parameters.hpp"
#include "vvariables/model_variables.hpp"

template <typename TDimensions>
inline Variables<Poisson, TDimensions>
get_variables(const Parameters<Poisson, TDimensions>& parameters) {
  return {};
}
