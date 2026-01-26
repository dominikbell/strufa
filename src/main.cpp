#include <omp.h>

#include <highfive/H5File.hpp>
#include <iostream>
#include <vector>

#include "initialization/initialize_variables.hpp"
#include "io/input_parser.hpp"
#include "io/output_handler.hpp"
#include "models/run.hpp"
#include "parameters/parameters.hpp"
#include "vvariables/vvariables.hpp"

int main(int argc, char* argv[]) {
  // TODO: parallelization with MPI
  int mpi_size = 1;
  int rank = 0;
  // Get OMP information
  int omp_size {omp_get_max_threads()};
  MetaData meta_data {"meta.txt", mpi_size, omp_size};

  std::vector<double> my_data = {1.0, 2.0, 3.0, 4.0, 5.0};

  // Open file normally (Serial)
  HighFive::File file("output.h5", HighFive::File::ReadWrite | HighFive::File::Create | HighFive::File::Truncate);

  // Create a dataset
  HighFive::DataSet dataset = file.createDataSet<double>("/data", HighFive::DataSpace({my_data.size()}));

  // Write data
  dataset.write(my_data);

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
  } else {
    std::cout << "Please provide the path to the input file as an argument.\n";
  }

  return 0;
}
