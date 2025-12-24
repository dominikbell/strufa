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
  std::pair<int, int> pair_dimensions = get_space_and_velocity_dimensions(input);
  int space_dimensions = pair_dimensions.first;
  int velocity_dimensions = pair_dimensions.second;

  Space_Velocity_Dimension dimensionality {get_space_velocity_dimension(space_dimensions, velocity_dimensions)};

  Space_Dimension space_dimension {get_space_dimension(dimensionality)};

  /* holds_alternative checks at runtime, is_same_v at compile time
  if (std::holds_alternative<Dimensions_1D>(space_dimension)) {
    std::cout << "The code being run is one-dimensional.\n";
  } else {
    std::cout << "Something went wrong.\n";
  }
  */

  Advection_Parameters_Type parameters {get_parameters_advection(dimensionality, input)};
  Advection_Variables_Type variables {get_variables(parameters)};

  // TODO: this is what we want
  // initialize_variables(variables, input);
}
