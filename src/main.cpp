#include <mpi.h>
#include <omp.h>
#include <iostream>

#include "initialization/initialize_variables.hpp"
#include "io/input_parser.hpp"
#include "io/output_handler.hpp"
#include "models/run.hpp"
#include "parameters/parameters.hpp"
#include "vvariables/vvariables.hpp"

int main(int argc, char* argv[]) {
  // Get MPI information
  MPI_Init(&argc, &argv);
  int rank;
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  int mpi_size;
  MPI_Comm_size(MPI_COMM_WORLD, &mpi_size);

  // Get OMP information
  int omp_size {omp_get_max_threads()};
  MetaData meta_data {"meta.txt", mpi_size, omp_size};

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
    std::cout << "Starting the run.\n";
    meta_data.set_start_run_time();
    run(variables, parameters);
    meta_data.set_end_run_time();
    std::cout << "Finished the run.\n";

    if (rank == 0) {
      meta_data.write_meta_data();
    }
  }

  MPI_Finalize();

  return 0;
}
