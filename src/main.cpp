#include <iostream>
#include <utility>

#include "io/input_parser.hpp"
#include "initialization/initialize_variables.hpp"
#include "models/base/models.hpp"
#include "parameters/domain_parameters.hpp"
#include "parameters/parameters.hpp"
#include "vvariables/vvariables.hpp"

int main(int argc, char* argv[]) {
  if (argc > 1) {
    std::cout << "Program was called with parameter " << argv[1] << '\n';

    const Input input {parse_input(argv)};
    std::string model_name {model_enum_to_string(input.model)};
    std::cout << "The model name is " << model_name << ".\n";

    std::pair<int, int> pair_dimensions = get_space_and_velocity_dimensions(input);

    // Every model has a physical domain
    DomainParametersVariant domain_parameters {get_domain_parameters(pair_dimensions.first, input.file)};

    // Discretization details
    ParametersVariant parameters {get_parameters(input.model, pair_dimensions, input.file)};

    // Allocate the variables
    VariablesVariant variables {get_variables(pair_dimensions, parameters)};

    // Set initial conditions
    initialize_variables(pair_dimensions, variables, input.file, domain_parameters);

    // Run the model
    // run(variables, domain_parameters); (might be time loop or just solving, e.g., Poisson)
  }

  return 0;
}
