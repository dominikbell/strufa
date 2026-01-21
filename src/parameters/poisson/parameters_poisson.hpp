#pragma once

#include <variant>

#include "models/base/models.hpp"
#include "parameters/discretization/FE_parameters.hpp"
#include "parameters/domain_parameters.hpp"
#include "parameters/model_parameters.hpp"
#include "utilities/dimensions.hpp"

template <typename TDimensions>
struct Parameters<Poisson, TDimensions> {
  using SpaceDimensions = TDimensions::SpaceOnly;
  const DomainParameters<SpaceDimensions> domain_parameters;
  const FiniteElementParameters<SpaceDimensions> fe_parameters;
};

using PoissonParametersVariant = std::variant<
    Parameters<Poisson, D1>,
    Parameters<Poisson, D2>,
    Parameters<Poisson, D3> >;
