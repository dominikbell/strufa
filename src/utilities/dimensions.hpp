#pragma once

#include <variant>

#include "utilities/utilities.hpp"

// TODO: dimensions or dimension? Decide for one naming convention

struct Dimensions1D {};
struct Dimensions2D {};
struct Dimensions3D {};
struct Dimensions1V {};
struct Dimensions2V {};
struct Dimensions3V {};
struct Dimensions1D1V {};
struct Dimensions1D2V {};
struct Dimensions1D3V {};
struct Dimensions2D2V {};
struct Dimensions2D3V {};
struct Dimensions3D3V {};

using SpaceDimensions = std::variant<Dimensions1D>;
// using SpaceDimensions = std::variant<Dimensions1D, Dimensions2D, Dimensions3D>;
using VelocityDimensions = std::variant<Dimensions1V, Dimensions2V, Dimensions3V>;
using SpaceVelocityDimensions = std::variant<Dimensions1D1V, Dimensions1D2V>;
// using SpaceVelocityDimensions = std::variant<Dimensions1D1V, Dimensions1D2V, Dimensions1D3V, Dimensions2D2V, Dimensions2D3V, Dimensions3D3V>;

inline SpaceDimensions get_space_dimensions(int space_dimensions) {
  if (space_dimensions == 1) {
    return Dimensions1D();
  // } else if (space_dimensions == 2) {
  //   return Dimensions2D();
  // } else if (space_dimensions == 3) {
  //   return Dimensions3D();
  } else {
    exit_with_failure("space dimensions", space_dimensions);
  }
}

inline SpaceDimensions get_space_dimensions(SpaceVelocityDimensions space_velocity_dimension) {
  return std::visit([](auto&& arg) -> SpaceDimensions {
    using T = std::decay_t<decltype(arg)>;

    if constexpr (
      std::is_same_v<T, Dimensions1D1V> ||
      std::is_same_v<T, Dimensions1D2V>
    ) {
      return Dimensions1D{};
    } else {
      exit_with_failure("space velocity dimension");
    } }, space_velocity_dimension);
}

inline SpaceVelocityDimensions get_space_velocity_dimensions(int space_dimensions, int velocity_dimensions) {
  if (velocity_dimensions == 1) {
    if (space_dimensions == 1) {
      return Dimensions1D1V();
    } else {
      exit_with_failure("space dimensions", space_dimensions);
    }
  } else if (velocity_dimensions == 2) {
    if (space_dimensions == 1) {
      return Dimensions1D2V();
    } else {
      exit_with_failure("space dimensions", space_dimensions);
    }
  } else {
    exit_with_failure("velocity dimensions", velocity_dimensions);
  }
}

// inline SpaceVelocityDimensions get_space_velocity_dimensions(int space_dimensions, int velocity_dimensions) {
//   if (velocity_dimensions == 1) {
//     if (space_dimensions == 1) {
//       return Dimensions1D1V();
//     } else if (space_dimensions == 2) {
//       std::string message {"Invalid combination of space dimensions and velocity dimensions detected!"};
//       exit_with_failure(message);
//     } else if (space_dimensions == 3) {
//       std::string message {"Invalid combination of space dimensions and velocity dimensions detected!"};
//       exit_with_failure(message);
//     } else {
//       exit_with_failure("space dimensions", space_dimensions);
//     }
//   } else if (velocity_dimensions == 2) {
//     if (space_dimensions == 1) {
//       return Dimensions1D2V();
//     } else if (space_dimensions == 2) {
//       return Dimensions2D2V();
//     } else if (space_dimensions == 3) {
//       std::string message {"Invalid combination of space dimensions and velocity dimensions detected!"};
//       exit_with_failure(message);
//     } else {
//       exit_with_failure("space dimensions", space_dimensions);
//     }
//   } else if (velocity_dimensions == 3) {
//     if (space_dimensions == 1) {
//       return Dimensions1D3V();
//     } else if (space_dimensions == 2) {
//       return Dimensions2D3V();
//     } else if (space_dimensions == 3) {
//       return Dimensions3D3V();
//     } else {
//       exit_with_failure("space dimensions", space_dimensions);
//     }
//   } else {
//     exit_with_failure("velocity dimensions", velocity_dimensions);
//   }
// }
