#include "FE_parameters.hpp"

FiniteElementParametersVariant get_fe_parameters(int space_dimensions, const json& data) {
  switch (space_dimensions) {
    case (1): {
      return get_fe_parameters<D1>(data);
    }
    case (2): {
      return get_fe_parameters<D2>(data);
    }
    case (3): {
      return get_fe_parameters<D3>(data);
    }
    default: {
      exit_with_failure("space dimensions", space_dimensions);
    }
  }
}
