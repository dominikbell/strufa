#include "space_initial_condition.hpp"

#include "utilities/utilities.hpp"

SpaceInitialVariant get_space_initial_condition(int space_dimensions, const json& data) {
  if (data.count("type") == 1) {
    SpaceInitialEnum space_initial {string_to_space_initial_enum(data["type"])};

    switch (space_initial) {
      case (SpaceInitialEnum::sine):
        return get_sine(space_dimensions, data);
      case (SpaceInitialEnum::cosine):
        return get_cosine(space_dimensions, data);
    }

  } else {
    exit_with_failure("Initialization in space must include keyword 'type'!\n");
  }
}
