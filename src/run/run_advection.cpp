#include <iostream>
#include <nlohmann/json.hpp>
#include <utility>

#include "io/input_parser.hpp"
#include "models/1D/advection/advection.hpp"
#include "parameters/parameters_advection.hpp"
#include "setup/setup_advection.hpp"
#include "vvariables/variables_advection.hpp"

void run_advection(const Input& input) {
  std::pair<int, int> pair = get_space_and_velocity_dimensions(input);
  int space_dims = pair.first;
  int velocity_dims = pair.second;
  std::cout << "The model being run has " << space_dims << " spatial dimension(s).\n";

  if (space_dims == 1) {
    if (velocity_dims == 1) {
      Parameters_Advection_1D1V parameters {get_parameters_advection_1d1v(input)};
      std::cout << "The model name is: " << parameters.model_name << '\n';

      Variables_Advection_1D1V variables {setup_advection(parameters)};
      std::cout << "The models first weight is: " << variables.particles.weights[0] << '\n';

      // } else if (velocity_dims == 2) {
      //   Parameters_Advection_1D2V parameters {get_parameters_advection_1d2v(input)};
      //   advection(parameters);
    }
  }
}