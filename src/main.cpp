#include <iostream>

#include "io/input_parser.hpp"
// #include "initialization/initialize_variables.hpp"
#include "parameters/parameters.hpp"
// #include "vvariables/vvariables.hpp"

int main(int argc, char* argv[]) {
  if (argc > 1) {
    std::cout << "Program was called with parameter " << argv[1] << '\n';

    const Input input {parse_input(argv)};

    // Discretization details
    ParametersVariant parameters {get_parameters(input.model_variant, input.dimensions_variant, input.file)};

    // // Allocate the variables
    // VariablesVariant variables {get_variables(pair_dimensions, parameters)};

    // // Set initial conditions
    // initialize_variables(pair_dimensions, variables, input.file, domain_parameters);

    // Run the model
    // run(variables, domain_parameters); (might be time loop or just solving, e.g., Poisson)
  }

  return 0;
}
