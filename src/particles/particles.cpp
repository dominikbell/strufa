#include "particles.hpp"

#include <cassert>
#include <iostream>
#include <nlohmann/json.hpp>
#include <optional>

#include "io/input_parser.hpp"

using json = nlohmann::json;

ParticleParameters get_particle_parameters(const json& data) {
  assert_top_level_keyword(data, "PIC");
  assert_second_level_keyword(data, "PIC", "N_markers");
  long N_markers {data["PIC"]["N_markers"]};

  std::string type_name = data["PIC"].value("type", "full_f");
  int seed = data["PIC"].value("seed", 1234);

  std::optional<Particle_Method> type {string_to_particle_method(type_name)};

  if (type) {
    ParticleParameters particle_parameters {
        *type,
        N_markers,
        seed};

    return particle_parameters;
  } else {
    std::cerr << "Particle type '" << type_name << "' is not a valid choice!\n";
    assert(type && "Invalid particle type entered, see line above.\n");
  }
}