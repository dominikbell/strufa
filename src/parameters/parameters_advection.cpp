#include "parameters_advection.hpp"

#include <nlohmann/json.hpp>

#include "io/input_parser.hpp"

using json = nlohmann::json;

Parameters_Advection_1D1V get_parameters_advection_1d1v(const Input& input) {
  json data {open_file(input.file_name)};

  // Make the background maxwellian
  double mu {data["initial_distribution"]["mu"]};
  double sigma {data["initial_distribution"]["sigma"]};
  double alpha {data["initial_distribution"]["alpha"]};
  Maxwellian maxwellian {mu, sigma, alpha};

  Parameters_Advection_1D1V parameters {
      // initialize Parameters_Advection
      {{model_to_string(input.model)},
       {data["time"]["dt"], data["time"]["T_end"]},
       {data["PIC"]["N_markers"], data["PIC"]["seed"]}},
      // initialize Parameters_1D
      {data["domain"]["length"]},
      // initialize Parameters_Advection_1D1V
      maxwellian,
  };
  return parameters;
}

// Parameters_Advection_1D2V get_parameters_advection_1d2v(const Input& input) {
//   return Parameters_Advection_1D2V();
// }