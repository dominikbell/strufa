#include <omp.h>

#include <cstddef>
#include <iostream>
#include <vector>
#include <iomanip>

#include "feec_utilities.hpp"
#include "initialization/initialize_variables.hpp"
#include "io/input_parser.hpp"
#include "io/output_handler.hpp"
#include "models/run.hpp"
#include "parameters/parameters.hpp"
#include "feec/splines.hpp"
#include "vvariables/vvariables.hpp"
#include "feec/feec_utilities.hpp"

int main(int argc, char* argv[]) {
  if (argc > 1) {
    // TODO: parallelization with MPI
    int mpi_size = 1;
    int rank = 0;
    MetaData meta_data {mpi_size};

    const Input input {parse_input(argc, argv)};

    int degree {2};
    double domain_length {17.34};
    size_t n_points {408};
    std::vector<double> knots {make_knots(domain_length, n_points, degree)};
    double grid_spacing {knots[degree + 1]};
    double point {4.175};
    int span {find_span(point, grid_spacing, degree)};

    std::vector<double> out_b(degree + 1, 0.0);
    std::vector<double> out_d(degree, 0.0);
    std::vector<double> out2_b(degree + 1, 0.0);
    std::vector<double> out2_d(degree, 0.0);

    eval_b_d_splines(point, degree, span, grid_spacing, out_b, out_d);
    eval_b_d_splines_struphy(knots, degree, point, span, out2_b, out2_d);

    std::cout << "Result for B-splines:\n[";
    for (auto& point : out_b) {
      std::cout << std::setprecision(15) << point << ", ";
    }
    std::cout << "]\n\n";

    std::cout << "Struphy Result for B-splines:\n[";
    for (auto& point : out2_b) {
      std::cout << std::setprecision(15) << point << ", ";
    }
    std::cout << "]\n\n";

    std::cout << "Difference:\n[";
    double diff {};
    for (size_t ind = 0; ind < degree + 1; ++ind) {
      diff = out_b[ind] - out2_b[ind];
      std::cout << std::setprecision(15) << diff << ", ";
    }
    std::cout << "]\n\n";

    std::cout << "Result for D-splines:\n[";
    for (auto& point : out_d) {
      std::cout << std::setprecision(15) << point << ", ";
    }
    std::cout << "]\n\n";

    std::cout << "Struphy Result for D-splines:\n[";
    for (auto& point : out2_d) {
      std::cout << std::setprecision(15) << point << ", ";
    }
    std::cout << "]\n\n";

    std::cout << "Difference:\n[";
    double diff_d {};
    for (size_t ind = 0; ind < degree; ++ind) {
      diff_d = out_d[ind] - out2_d[ind];
      std::cout << std::setprecision(15) << diff_d << ", ";
    }
    std::cout << "]\n\n";

    // // Discretization details
    // ParametersVariant parameters {get_parameters(input.model_variant, input.dimensions_variant, input.file)};

    // // Allocate the variables
    // VariablesVariant variables {get_variables(parameters, input)};

    // // // Set initial conditions
    // initialize_variables(variables, parameters, input.file);

    // // Run the model
    // // (might be time loop or just solving, e.g., Poisson)
    // std::cout << "Starting the run.\n";
    // meta_data.set_start_run_time();
    // run(variables, parameters);
    // meta_data.set_end_run_time();
    // std::cout << "Finished the run.\n";

    // if (rank == 0) {
    //   meta_data.write_meta_data(input.output_path);
    // }
  } else {
    std::cout << "Please provide the path to the input file as an argument.\n";
  }

  return 0;
}
