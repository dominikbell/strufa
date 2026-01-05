#include "PIC_parameters.hpp"

#include "io/input_parser.hpp"

ParticleParameters get_particle_parameters(const json& data) {
  assert_top_level_keyword(data, "PIC");
  assert_second_level_keyword(data, "PIC", "type");
  assert_second_level_keyword(data, "PIC", "N_markers");
  assert_second_level_keyword(data, "PIC", "seed");

  std::string particle_type_name {data["PIC"]["type"]};
  ParticleTypeEnum particle_type {string_to_particle_type_enum(particle_type_name)};
  long N_markers {data["PIC"]["N_markers"]};
  int seed {data["PIC"]["seed"]};

  return {
    particle_type,
    N_markers,
    seed
  };
}
