#include <omp.h>

#include <cstddef>
#include <iostream>
#include <vector>

#include "feec/matrices.hpp"
#include "feec_utilities.hpp"
// #include "initialization/initialize_variables.hpp"
#include "io/input_parser.hpp"
#include "io/output_handler.hpp"
// #include "models/run.hpp"
// #include "parameters/parameters.hpp"
// #include "vvariables/vvariables.hpp"

int main(int argc, char* argv[]) {
  if (argc > 1) {
    // TODO: parallelization with MPI
    int mpi_size = 1;
    int rank = 0;
    MetaData meta_data {mpi_size};

    const Input input {parse_input(argc, argv)};

    double domain_length {2.734};
    size_t n_points {33};

    double grid_spacing {get_grid_spacing(domain_length, n_points)};

    Circulant spline_coll {get_spline_collocation(n_points, grid_spacing)};
    Circulant spline_hist {get_spline_histopolation(n_points, grid_spacing)};

    std::cout << "Spline collocation matrix entries: \n[";
    for (double col: spline_coll.entries) {
      std::cout << col << ", ";
    }
    std::cout << "]\n\n";
    std::cout << "Spline collocation matrix columns: \n[";
    for (size_t col_ind: spline_coll.cols ) {
      std::cout << col_ind << ", ";
    }
    std::cout << "]\n\n\n";

    std::cout << "Spline histopolation matrix entries: \n[";
    for (size_t col: spline_hist.entries) {
      std::cout << col << ", ";
    }
    std::cout << "]\n\n";
    std::cout << "Spline histopolation matrix columns: \n[";
    for (size_t col_ind: spline_hist.cols) {
      std::cout << col_ind << ", ";
    }
    std::cout << "]\n";

    // // Discretization details
    // ParametersVariant parameters {get_parameters(input.model_variant, input.dimensions_variant, input.file)};

    // // Allocate the variables
    // VariablesVariant variables {get_variables(parameters, input)};

    // // Set initial conditions
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
