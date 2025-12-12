#include <iostream>
#include <optional>

#include "io/input_parser.hpp"

int main(int argc, char* argv[]) {
  if (argc > 1) {
    std::cout << "Program was called with parameter " << argv[1] << '\n';

    const Input input = parse_input(argv);
    std::cout << "The model name is " << input.model_name << '\n';

    /** PSEUDO CODE
     * const Input input = parser(argv[1])
     *
     * switch (input.model_name) {
     * case "Advection": {
     *  run_advection(input);
     * }
     * case "Poisson": {
     *  run_poisson(input);
     * }
     * }
     */
  } else {
    std::cout << "Program was called without additional parameters.\n";
  }

  return 0;
}