#include <iostream>
#include <utility>
#include <nlohmann/json.hpp>

#include "io/input_parser.hpp"
#include "parameters/parameters_advection.hpp"
#include "models/1D/advection/advection.hpp"

void run_advection(const Input& input) {
  std::pair<int, int> pair = get_space_and_velocity_dimensions(input);
  int space_dims = pair.first;
  int velocity_dims = pair.second;
  std::cout << "The model being run has " << space_dims << " spatial dimension(s).\n";
  if (space_dims == 1) {
    if (velocity_dims == 1) {
      Parameters_Advection_1D1V parameters {get_parameters_advection_1d1v()};
      advection(parameters);
    } else if (velocity_dims == 2) {
      Parameters_Advection_1D2V parameters {get_parameters_advection_1d2v()};
      advection(parameters);
    }
  }
}