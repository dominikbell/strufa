#include <mpi.h>
#include <omp.h>

// #include "initialization/initialize_variables.hpp"
// #include "io/input_parser.hpp"
#include "io/output_handler.hpp"
// #include "models/run.hpp"
// #include "parameters/parameters.hpp"
// #include "vvariables/vvariables.hpp"

int main(int argc, char* argv[]) {
  MPI_Init(&argc, &argv);
  int rank;
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  int mpi_size;
  MPI_Comm_size(MPI_COMM_WORLD, &mpi_size);

  int omp_size {omp_get_max_threads()};
  MetaData meta_data {"meta.txt", mpi_size, omp_size};

  if (rank == 0) {
    meta_data.write_meta();
  }

  MPI_Finalize();

  // if (argc > 1) {
  //   std::cout << "Program was called with parameter " << argv[1] << '\n';

  //   const Input input {parse_input(argv)};

  //   // Discretization details
  //   ParametersVariant parameters {get_parameters(input.model_variant, input.dimensions_variant, input.file)};

  //   // Allocate the variables
  //   VariablesVariant variables {get_variables(parameters)};

  //   // // Set initial conditions
  //   initialize_variables(variables, parameters, input.file);

  //   // Run the model
  //   // (might be time loop or just solving, e.g., Poisson)
  //   run(variables, parameters);
  // }

  return 0;
}
