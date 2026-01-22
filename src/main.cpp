#include <iostream>

#include "io/input_parser.hpp"
#include "initialization/initialize_variables.hpp"
#include "models/run.hpp"
#include "parameters/parameters.hpp"
#include "vvariables/vvariables.hpp"

int main(int argc, char* argv[]) {
  if (argc > 1) {
    std::cout << "Program was called with parameter " << argv[1] << '\n';

    const Input input {parse_input(argv)};

    // Discretization details
    ParametersVariant parameters {get_parameters(input.model_variant, input.dimensions_variant, input.file)};

    // Allocate the variables
    VariablesVariant variables {get_variables(parameters)};

    // // Set initial conditions
    initialize_variables(variables, parameters, input.file);

    // Run the model
    // (might be time loop or just solving, e.g., Poisson)
    run(variables, parameters);
  }

  return 0;
}
