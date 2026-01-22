#include "get_parameters_poisson.hpp"

#include <type_traits>
#include <variant>

#include "models/base/models.hpp"
#include "parameters/discretization/FE_parameters.hpp"
#include "parameters/domain_parameters.hpp"
#include "parameters/model_parameters.hpp"
#include "parameters/parameters.hpp"
#include "parameters_poisson.hpp"
#include "utilities/dimensions.hpp"
#include "utilities/utilities.hpp"

template <>
ParametersVariant get_parameters<Poisson>(
    const DimensionsVariant& dimensions_variant,
    const json& data) {
  return std::visit([&](const auto& dimensions) -> PoissonParametersVariant {
    using Dimensions = std::decay_t<decltype(dimensions)>;
    using SpaceDimensions = std::decay_t<decltype(dimensions)>::SpaceOnly;

    if constexpr (Dimensions::space_dimensions > 0 && Dimensions::velocity_dimensions == 0) {
      const DomainParameters<SpaceDimensions> domain_parameters {get_domain_parameters<SpaceDimensions>(data)};
      const FiniteElementParameters<SpaceDimensions> fe_parameters {get_fe_parameters<SpaceDimensions>(data)};
      const Parameters<Poisson, Dimensions> poisson_parameters {domain_parameters, fe_parameters};
      return poisson_parameters;
    } else {
      exit_with_failure("Space dimensions for poisson must be non-zero and velocity dimensions must be zero!");
    }
  },
                    dimensions_variant);
}
