#pragma once

#include <utility>
#include <variant>

#include "io/input_parser.hpp"
#include "models/base/models.hpp"
#include "parameters/discretization/FE_parameters.hpp"
#include "parameters/model_parameters.hpp"
#include "utilities/dimensions.hpp"

template <typename Dimensions>
struct Parameters<Poisson, Dimensions> {
  const FiniteElementParameters<Dimensions> fe_parameters;
};

using PoissonParametersVariant = std::variant<
    Parameters<Poisson, D1>,
    Parameters<Poisson, D2>,
    Parameters<Poisson, D3> >;

template <typename Dimensions>
inline Parameters<Poisson, Dimensions>
get_parameters_poisson(const json& data) {
  FiniteElementParameters<Dimensions> fe_parameters {get_fe_parameters<Dimensions>(data)};

  return {fe_parameters};
}

PoissonParametersVariant get_parameters_poisson(std::pair<int, int> pair_dimensions, const json& data);
