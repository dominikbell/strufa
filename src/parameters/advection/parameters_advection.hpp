#pragma once

#include <vector>

#include "from_dimensions_advection.hpp"
#include "functions/maxwellian.hpp"
#include "io/input_parser.hpp"
#include "parameters/parameters.hpp"
#include "particles/particles.hpp"
#include "utilities/dimensions.hpp"

struct ParametersAdvection : BaseParameters, TimeParameters, ParticleParameters {
  ParametersAdvection(
      BaseParameters& parameters_i,
      TimeParameters& time_parameters_i,
      ParticleParameters& particle_parameters_i)
      : BaseParameters(parameters_i),
        TimeParameters(time_parameters_i),
        ParticleParameters(particle_parameters_i) {}
};

struct ParametersAdvection1D1V : ParametersAdvection, Parameters1D {
  ParametersAdvection1D1V(
      ParametersAdvection& parameters_advection_i,
      Parameters1D& parameters_1d_i)
      : ParametersAdvection(parameters_advection_i),
        Parameters1D(parameters_1d_i) {}
};

struct ParametersAdvection1D2V : ParametersAdvection, Parameters1D {
  ParametersAdvection1D2V(
      ParametersAdvection& parameters_advection_i,
      Parameters1D& parameters_1d_i)
      : ParametersAdvection(parameters_advection_i),
        Parameters1D(parameters_1d_i) {}
};

using AdvectionParametersType = std::variant<ParametersAdvection1D1V, ParametersAdvection1D2V>;

// ParametersAdvection1D1V get_parameters_advection_dimensionful(const Dimensions1D1V& dimension, const Input& input);
// ParametersAdvection1D2V get_parameters_advection_dimensionful(const Dimensions1D2V& dimension, const Input& input);

// Original function for 1d1v
// ParametersAdvection1D1V get_parameters_advection_dimensionful(const Dimensions1D1V& dimension, const Input& input) {
//   BaseParameters parameters_base {get_base_parameters(input.file)};
//   TimeParameters time_parameters {get_time_parameters(input.file)};
//   ParticleParameters particle_parameters {get_particle_parameters(input.file)};
//   Parameters1D parameters_1d {get_parameters(input.file)};

//   ParametersAdvection parameters_advection {
//       parameters_base,
//       time_parameters,
//       particle_parameters};

//   ParametersAdvection1D1V parameters {
//       parameters_advection,
//       parameters_1d};

//   return parameters;
// }

template <typename T_in>
auto get_parameters_advection_dimensionful(const T_in& dimension, const Input& input) {
  BaseParameters parameters_base {get_base_parameters(input.file)};
  TimeParameters time_parameters {get_time_parameters(input.file)};
  ParticleParameters particle_parameters {get_particle_parameters(input.file)};

  using T_out = typename DimensionToParameter<T_in>::parameters_type;
  using T_space = typename DimensionToParameter<T_in>::space_parameters_type;

  SpaceDimensions space_dimensions {get_space_dimensions(dimension)};

  Parameters parameters_variant {get_parameters(space_dimensions, input.file)};
  T_space parameters_dimensionful = std::get<T_space>(parameters_variant);

  ParametersAdvection parameters_advection {
      parameters_base,
      time_parameters,
      particle_parameters};

  T_out parameters {
      parameters_advection,
      parameters_dimensionful};

  return parameters;
}

AdvectionParametersType get_parameters_advection(const SpaceVelocityDimensions& dimensions, const Input& input);
