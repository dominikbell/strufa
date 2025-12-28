#include <iostream>
#include <nlohmann/json.hpp>
#include <utility>
#include <variant>

#include "io/input_parser.hpp"
#include "models.hpp"
#include "models/1D/advection/advection_1D.hpp"
#include "parameters/advection/parameters_advection.hpp"
#include "utilities/dimensions.hpp"
#include "vvariables/advection/variables_advection.hpp"

void advection(const Input& input) {
  std::pair<int, int> pair_dimensions = get_space_and_velocity_dimensions(input);
  int space_dimensions = pair_dimensions.first;
  int velocity_dimensions = pair_dimensions.second;

  SpaceVelocityDimensions dimensionality {get_space_velocity_dimensions(space_dimensions, velocity_dimensions)};

  SpaceDimensions space_dimension {get_space_dimensions(dimensionality)};

  /* holds_alternative checks at runtime, is_same_v at compile time
  if (std::holds_alternative<Dimensions1D>(space_dimension)) {
    std::cout << "The code being run is one-dimensional.\n";
  } else {
    std::cout << "Something went wrong.\n";
  }
  */

  AdvectionParametersType parameters {get_parameters_advection(dimensionality, input)};
  AdvectionVariablesType variables {get_variables(parameters)};

  // TODO: this is what we want
  // initialize_variables(variables, input);
}
