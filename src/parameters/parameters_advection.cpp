#include "parameters_advection.hpp"

#include <nlohmann/json.hpp>

#include "io/input_parser.hpp"
#include "parameters/parameters.hpp"
#include "particles/particles.hpp"
#include "utilities/dimensionality.hpp"

using json = nlohmann::json;

Advection_Parameters_Type get_parameters_advection(const Space_Velocity_Dimension& dimensions, const Input& input) {
  return std::visit(
    [&input](auto arg) -> Advection_Parameters_Type {
      return get_parameters_advection_dimensionful(arg, input);
    }, dimensions
  );
}

Parameters_Advection_1D1V get_parameters_advection_dimensionful(const Dimensions_1D1V& dimension, const Input& input) {
  json data {open_file(input.file_name)};

  Parameters parameters_base {get_parameters(data)};
  TimeParameters time_parameters {get_time_parameters(data)};
  ParticleParameters particle_parameters {get_particle_parameters(data)};
  Parameters_1D parameters_1d {get_parameters_1d(data)};

  Parameters_Advection parameters_advection {
      parameters_base,
      time_parameters,
      particle_parameters};

  Parameters_Advection_1D1V parameters {
      parameters_advection,
      parameters_1d};

  return parameters;
}
