#include "domain_parameters.hpp"

DomainParametersVariant get_domain_parameters(int space_dimensions, const json& data) {
  SpaceDimensionsVariant space_dims {get_space_dimensions(space_dimensions)};

  return std::visit(
      [&](auto const& arg) -> DomainParametersVariant {
        using Dim = std::decay_t<decltype(arg)>;
        return get_domain_parameters<Dim>(data);
      },
      space_dims);
}
