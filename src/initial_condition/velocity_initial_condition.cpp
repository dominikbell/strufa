#include "velocity_initial_condition.hpp"

VelocityInitialVariant get_velocity_initial_condition(int velocity_dimensions, const json& data) {
  if (data.count("type") == 1) {
    VelocityInitialEnum velocity_initial {string_to_velocity_initial_enum(data["type"])};

    switch (velocity_initial) {
      case (VelocityInitialEnum::maxwellian):
        return get_maxwellian(velocity_dimensions, data);
    }

  } else {
    exit_with_failure("Initialization in velocity must include keyword 'type'!\n");
  }
}
