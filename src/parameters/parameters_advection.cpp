#include "parameters_advection.hpp"

#include <nlohmann/json.hpp>

#include "io/input_parser.hpp"

using json = nlohmann::json;

void check_file_advection(const json& data) {
  std::vector<std::string> domain_keys = {"length"};
  std::vector<std::string> time_keys = {"dt", "T_end"};
  std::vector<std::string> background_keys = {"mu", "sigma", "alpha"};
  std::vector<std::string> initial_keys = {"type"};
  std::vector<std::string> PIC_keys = {"N_markers", "seed"};
  // check top-level keys
  std::vector<std::pair<std::string, std::vector<std::string>>> keywords = {
      std::make_pair("domain", domain_keys),
      std::make_pair("time", time_keys),
      std::make_pair("background", background_keys),
      std::make_pair("initial", initial_keys),
      std::make_pair("PIC", PIC_keys),
  };
  for (std::pair<std::string, std::vector<std::string>> top_level_key : keywords) {
    assert_top_level_keyword(data, top_level_key.first);
    for (std::string keyword : top_level_key.second) {
      assert_second_level_keyword(data, top_level_key.first, keyword);
    }
  }
}

Parameters_Advection_1D1V get_parameters_advection_1d1v(const Input& input) {
  json data {open_file(input.file_name)};

  check_file_advection(data);

  // Make the background maxwellian
  double mu {data["background"]["mu"]};
  double sigma {data["background"]["sigma"]};
  double alpha {data["background"]["alpha"]};
  Maxwellian_1D maxwellian {mu, sigma, alpha};

  Parameters_Advection_1D1V parameters {
      // initialize Parameters_Advection
      {{model_to_string(input.model), data["initial"]},
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