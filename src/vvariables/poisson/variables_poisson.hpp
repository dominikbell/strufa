#pragma once

#include <variant>

#include "models/base/models.hpp"
#include "utilities/dimensions.hpp"
#include "vvariables/model_variables.hpp"

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
