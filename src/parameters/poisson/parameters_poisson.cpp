#include "parameters_poisson.hpp"

PoissonParametersVariant get_parameters_poisson(
    std::pair<int, int> pair_dimensions,
    const json& data) {
  const int space_dimensions = pair_dimensions.first;

  SpaceDimensionsVariant space_dims {get_space_dimensions(space_dimensions)};

  return std::visit(
      [&](auto dim) -> PoissonParametersVariant {
        using Dim = std::decay_t<decltype(dim)>;
        return get_parameters_poisson<Dim>(data);
      },
      space_dims);
}
