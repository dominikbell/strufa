#pragma once

#include <variant>

#include "vvariables/model_variables.hpp"
#include "parameters/poisson/parameters_poisson.hpp"

template <typename Dimensions>
struct Variables<Poisson, Dimensions> {

  auto as_tuple() {
    return std::tie();
  }

  // keys (metadata)
  static constexpr auto keys() {
    return std::make_tuple();
  }
};

using PoissonVariablesVariant = std::variant<
    Variables<Poisson, D1>,
    Variables<Poisson, D2>,
    Variables<Poisson, D3> >;

template <typename Dimensions>
inline Variables<Poisson, Dimensions>
get_variables_poisson(const PoissonParametersVariant& parameters) {
  return {};
}

PoissonVariablesVariant get_variables_poisson(std::pair<int, int> pair_dimensions, const PoissonParametersVariant& parameters);
