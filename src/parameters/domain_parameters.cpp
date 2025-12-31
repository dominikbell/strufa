#include "domain_parameters.hpp"

DomainParametersVariant get_domain_parameters(int space_dimensions, const json& data) {
  switch (space_dimensions) {
    case (1): {
      return get_domain_parameters<D1>(data);
    }
    case (2): {
      return get_domain_parameters<D2>(data);
    }
    default: {
      exit_with_failure("space dimensions", space_dimensions);
    }
  }
}
