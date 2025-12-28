#include "parameters_advection.hpp"

#include <nlohmann/json.hpp>

#include "from_dimensions_advection.hpp"
#include "io/input_parser.hpp"
#include "parameters/parameters.hpp"
#include "particles/particles.hpp"
#include "utilities/dimensions.hpp"

using json = nlohmann::json;

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

// ParametersAdvection1D2V get_parameters_advection_dimensionful(const Dimensions1D2V& dimension, const Input& input) {
//   BaseParameters parameters_base {get_base_parameters(input.file)};
//   TimeParameters time_parameters {get_time_parameters(input.file)};
//   ParticleParameters particle_parameters {get_particle_parameters(input.file)};
//   Parameters1D parameters_1d {get_parameters(input.file)};

//   ParametersAdvection parameters_advection {
//       parameters_base,
//       time_parameters,
//       particle_parameters};

//   ParametersAdvection1D2V parameters {
//       parameters_advection,
//       parameters_1d};

//   return parameters;
// }

AdvectionParametersType get_parameters_advection(const SpaceVelocityDimensions& dimensions, const Input& input) {
  return std::visit(
      [&input](auto const& arg) -> AdvectionParametersType {
        return get_parameters_advection_dimensionful(arg, input);
      },
      dimensions);
}