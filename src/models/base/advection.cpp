#include <iostream>
#include <nlohmann/json.hpp>
#include <utility>
#include <variant>

#include "io/input_parser.hpp"
#include "models.hpp"
#include "models/1D/advection/advection_1D.hpp"
#include "parameters/parameters_advection.hpp"
#include "utilities/dimensionality.hpp"
#include "vvariables/variables_advection.hpp"

void advection(const Input& input) {
  std::pair<int, int> pair = get_space_and_velocity_dimensions(input);
  int space_dimensions = pair.first;
  int velocity_dimensions = pair.second;

  Space_Velocity_Dimension dimensionality {get_space_velocity_dimension(space_dimensions, velocity_dimensions)};

  Advection_Parameters_Type parameters {get_parameters_advection(dimensionality, input)};
  Advection_Variables_Type variables {get_variables(parameters)};
  // initialize_variables(variables, parameters); TODO: this is what we want
}
