#include "get_parameters_advection.hpp"

#include <type_traits>
#include <variant>

#include "discretization/PIC_parameters.hpp"
#include "models/base/models.hpp"
#include "parameters/domain_parameters.hpp"
#include "parameters/model_parameters.hpp"
#include "parameters/parameters.hpp"
#include "parameters/time_parameters.hpp"
#include "parameters_advection.hpp"
#include "utilities/dimensions.hpp"
#include "utilities/utilities.hpp"

template <>
ParametersVariant get_parameters<Advection>(
    const DimensionsVariant& dimensions_variant,
    const json& data) {
  return std::visit([&](const auto& dimensions) -> AdvectionParametersVariant {
    using Dimensions = std::decay_t<decltype(dimensions)>;
    using SpaceDimensions = std::decay_t<decltype(dimensions)>::SpaceOnly;

    if constexpr (Dimensions::space_dimensions > 0 && Dimensions::velocity_dimensions > 0) {
      const DomainParameters<SpaceDimensions> domain_parameters {get_domain_parameters<SpaceDimensions>(data)};
      const TimeParameters time_parameters {get_time_parameters(data)};
      const ParticleParameters particle_parameters {get_particle_parameters(data)};
      const Parameters<Advection, Dimensions> advection_parameters {domain_parameters, time_parameters, particle_parameters};
      return advection_parameters;
    } else {
      exit_with_failure("Velocity and space dimensions for advection must be non-zero!");
    }
  },
                    dimensions_variant);
}
