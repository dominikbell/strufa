#include "space_initial_condition.hpp"

#include "parameters/domain_parameters.hpp"
#include "utilities/utilities.hpp"

SpaceInitialVariant get_space_initial_condition(
    const json& initial_data,
    const DomainParametersVariant& domain_parameters) {
  if (initial_data.count("type") == 1) {
    SpaceInitialEnum space_initial {string_to_space_initial_enum(initial_data["type"])};

    switch (space_initial) {
      case (SpaceInitialEnum::sine):
        return get_sine(initial_data, domain_parameters);
      case (SpaceInitialEnum::cosine):
        return get_cosine(initial_data, domain_parameters);
    }

  } else {
    exit_with_failure("Initialization in space must include keyword 'type'!\n");
  }
}
