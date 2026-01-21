#include "dimensions.hpp"

#include "utilities.hpp"

SpaceDimensionsVariant get_space_dimensions(int space_dimensions) {
  switch (space_dimensions) {
    case (1):
      return D1 {};
    case (2):
      return D2 {};
    case (3):
      return D3 {};
    default:
      exit_with_failure("space dimensions", space_dimensions);
  }
}

VelocityDimensionsVariant get_velocity_dimensions(int velocity_dimensions) {
  switch (velocity_dimensions) {
    case (1):
      return V1 {};
    case (2):
      return V2 {};
    case (3):
      return V3 {};
    default:
      exit_with_failure("velocity dimensions", velocity_dimensions);
  }
}

PhaseSpaceDimensionsVariant get_phase_space_dimensions(std::pair<int, int> pair_dimensions) {
  const int space_dimensions = pair_dimensions.first;
  const int velocity_dimensions = pair_dimensions.second;

  std::string failure_message {"Incompatible velocity dimensions " + std::to_string(velocity_dimensions) + " with space dimensions " + std::to_string(space_dimensions)};

  switch (space_dimensions) {
    case (1): {
      switch (velocity_dimensions) {
        case (1):
          return D1V1 {};
        case (2):
          return D1V2 {};
        case (3):
          return D1V3 {};
        default:
          exit_with_failure(failure_message);
      }
    }
    case (2): {
      switch (velocity_dimensions) {
        case (2):
          return D2V2 {};
        case (3):
          return D2V3 {};
        default:
          exit_with_failure(failure_message);
      }
      case (3): {
        switch (velocity_dimensions) {
          case (3):
            return D3V3 {};
          default:
            exit_with_failure(failure_message);
        }
      }
      default:
        exit_with_failure("space dimensions", space_dimensions);
    }
  }
}

// very beautiful function...
DimensionsVariant get_dimensions(const std::pair<int, int>& pair_dimensions) {
  const int space_dimensions = pair_dimensions.first;
  const int velocity_dimensions = pair_dimensions.second;

  if (space_dimensions == 0) {
    switch (velocity_dimensions) {
      case (1):
        return V1 {};
      case (2):
        return V2 {};
      case (3):
        return V3 {};
      default:
        exit_with_failure("velocity dimensions", velocity_dimensions);
    }
  } else {
    if (velocity_dimensions == 0) {
      switch (space_dimensions) {
        case (1):
          return D1 {};
        case (2):
          return D2 {};
        case (3):
          return D3 {};
        default:
          exit_with_failure("space dimensions", space_dimensions);
      }
    } else {
      std::string failure_message {"Incompatible velocity dimensions " + std::to_string(velocity_dimensions) + " with space dimensions " + std::to_string(space_dimensions)};

      switch (space_dimensions) {
        case (1): {
          switch (velocity_dimensions) {
            case (1):
              return D1V1 {};
            case (2):
              return D1V2 {};
            case (3):
              return D1V3 {};
            default:
              exit_with_failure(failure_message);
          }
        }
        case (2): {
          switch (velocity_dimensions) {
            case (2):
              return D2V2 {};
            case (3):
              return D2V3 {};
            default:
              exit_with_failure(failure_message);
          }
          case (3): {
            switch (velocity_dimensions) {
              case (3):
                return D3V3 {};
              default:
                exit_with_failure(failure_message);
            }
          }
          default:
            exit_with_failure("space dimensions", space_dimensions);
        }
      }
    }
  }
}
