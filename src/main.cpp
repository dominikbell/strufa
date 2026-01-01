#include <iostream>
#include <utility>

#include "io/input_parser.hpp"
#include "models/base/models.hpp"
#include "parameters/domain_parameters.hpp"
#include "parameters/parameters.hpp"
#include "utilities/dimensions.hpp"
#include "vvariables/vvariables.hpp"

int main(int argc, char* argv[]) {
  if (argc > 1) {
    std::cout << "Program was called with parameter " << argv[1] << '\n';

    const Input input {parse_input(argv)};
    std::string model_name {input.file["model"]};
    std::cout << "The model name is " << model_name << ".\n";

    std::pair<int, int> pair_dimensions = get_space_and_velocity_dimensions(input);

    DomainParametersVariant domain_parameters {get_domain_parameters(pair_dimensions.first, input.file)};

    // ModelVariant parameters are essentially the discretization parameters for the variables of this model
    ParametersVariant parameters {get_parameters(input.model, pair_dimensions, input.file)};

    VariablesVariant variables {get_variables(pair_dimensions, parameters)};
    // InitialConditions initial_conditions {get_initial_conditions(input)}
    // initialize_variables(model, initial_conditions);
    // run(model, variables); (might be time loop or just solving, e.g., Poisson)

    // switch (input.model) {
    //   case ModelVariant::advection: {
    //     advection(input);
    //   }
    //   case ModelVariant::poisson: {
    //   }
    // }
  }

  return 0;
}
