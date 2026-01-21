#pragma once

#include <variant>

#include "models/base/models.hpp"
#include "parameters/discretization/PIC_parameters.hpp"
#include "parameters/domain_parameters.hpp"
#include "parameters/model_parameters.hpp"
#include "parameters/time_parameters.hpp"
#include "utilities/dimensions.hpp"

template <typename TDimensions>
struct Parameters<Advection, TDimensions> {
  using SpaceDimensions = TDimensions::SpaceOnly;
  const DomainParameters<SpaceDimensions> domain_parameters;
  const TimeParameters time_parameters;
  const ParticleParameters particle_parameters;
};

using AdvectionParametersVariant = std::variant<
    Parameters<Advection, D1V1>,
    Parameters<Advection, D1V2>,
    Parameters<Advection, D1V3>,
    Parameters<Advection, D2V2>,
    Parameters<Advection, D2V3>,
    Parameters<Advection, D3V3> >;
