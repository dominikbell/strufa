#include <iostream>
#include <optional>

#include "io/input_parser.hpp"
#include "models/base_models/base_models.hpp"

int main(int argc, char* argv[]) {
  if (argc > 1) {
    std::cout << "Program was called with parameter " << argv[1] << '\n';

    const Input input = parse_input(argv);
    std::cout << "The model name is " << model_to_string(input.model) << ".\n";

    switch (input.model) {
      case Model::advection: {
        // run_advection(input);
      }
      case Model::poisson: {}
    }

  } else {
    std::cout << "Program was called without additional parameters. Exiting. \n";
  }

  return 0;
}