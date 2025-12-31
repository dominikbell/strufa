#include "parameters_poisson.hpp"

PoissonParametersVariant get_parameters_poisson(std::pair<int, int> pair_dimensions, const json& data) {
  const int space_dimensions = pair_dimensions.first;

  switch (space_dimensions) {
    case (1) : {
      return get_parameters_poisson<D1>(data);
    }
    case (2) : {
      return get_parameters_poisson<D2>(data);
    }
    case (3) : {
      return get_parameters_poisson<D3>(data);
    }
    default : {
      exit_with_failure("space dimensions", space_dimensions);
    }
  }
}
