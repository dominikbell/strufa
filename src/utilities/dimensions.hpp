#pragma once

#include <string>
#include <utility>
#include <variant>

#include "utilities.hpp"

template <int SpaceDimensions, int VelocityDimensions = 0>
struct Dimensions {
  static constexpr int space_dimensions = SpaceDimensions;
  static constexpr int velocity_dimensions = VelocityDimensions;
};

using D1 = Dimensions<1>;
using D2 = Dimensions<2>;
using D3 = Dimensions<3>;
using D1V1 = Dimensions<1, 1>;
using D1V2 = Dimensions<1, 2>;
using D1V3 = Dimensions<1, 3>;
using D2V2 = Dimensions<2, 2>;
using D2V3 = Dimensions<2, 3>;
using D3V3 = Dimensions<3, 3>;

using SpaceDimensionsVariant = std::variant<D1, D2, D3>;
using PhaseSpaceDimensionsVariant = std::variant<
    D1V1,
    D1V2,
    D1V3,
    D2V2,
    D2V3,
    D3V3>;

inline SpaceDimensionsVariant get_space_dimensions(int space_dimensions) {
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

inline PhaseSpaceDimensionsVariant get_phase_space_dimensions(std::pair<int, int> pair_dimensions) {
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
