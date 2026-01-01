#include "variables_poisson.hpp"

PoissonVariablesVariant get_variables_poisson(
  std::pair<int, int> pair_dimensions,
  const PoissonParametersVariant& parameters) {

  SpaceDimensionsVariant space_dims {get_space_dimensions(pair_dimensions.first)};

  return std::visit(
    [&](auto const arg) -> PoissonVariablesVariant {
      using Dim = std::decay_t<decltype(arg)>;
      return get_variables_poisson<Dim>(parameters);
    },
  space_dims);
}
