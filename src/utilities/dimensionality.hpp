#pragma once

#include <variant>

#include "utilities/utilities.hpp"

// TODO: dimensions or dimension? Decide for one naming convention

struct Dimensions_1D {};
struct Dimensions_2D {};
struct Dimensions_3D {};
struct Dimensions_1V {};
struct Dimensions_2V {};
struct Dimensions_3V {};
struct Dimensions_1D1V {};
struct Dimensions_1D2V {};
struct Dimensions_1D3V {};
struct Dimensions_2D2V {};
struct Dimensions_2D3V {};
struct Dimensions_3D3V {};

using Space_Dimension = std::variant<Dimensions_1D, Dimensions_2D, Dimensions_3D>;
using Velocity_Dimension = std::variant<Dimensions_1V, Dimensions_2V, Dimensions_3V>;
using Space_Velocity_Dimension = std::variant<Dimensions_1D1V, Dimensions_1D2V>;
// using Space_Velocity_Dimension = std::variant<Dimensions_1D1V, Dimensions_1D2V, Dimensions_1D3V, Dimensions_2D2V, Dimensions_2D3V, Dimensions_3D3V>;

inline Space_Dimension get_space_dimension(int space_dimensions) {
  if (space_dimensions == 1) {
    return Dimensions_1D();
  } else if (space_dimensions == 2) {
    return Dimensions_2D();
  } else if (space_dimensions == 3) {
    return Dimensions_3D();
  } else {
    exit_with_failure("space dimensions", space_dimensions);
  }
}

inline Space_Dimension get_space_dimension(Space_Velocity_Dimension space_velocity_dimension) {
  return std::visit([](auto&& arg) -> Space_Dimension {
    using T = std::decay_t<decltype(arg)>;

    if constexpr (std::is_same_v<T, Dimensions_1D1V>) {
      return Dimensions_1D{};
    } else {
      exit_with_failure("space velocity dimension");
    } }, space_velocity_dimension);
}

inline Space_Velocity_Dimension get_space_velocity_dimension(int space_dimensions, int velocity_dimensions) {
  if (velocity_dimensions == 1) {
    if (space_dimensions == 1) {
      return Dimensions_1D1V();
    } else {
      exit_with_failure("space dimensions", space_dimensions);
    }
  } else {
    exit_with_failure("velocity dimensions", velocity_dimensions);
  }
}
// inline Space_Velocity_Dimension get_space_velocity_dimension(int space_dimensions, int velocity_dimensions) {
//   if (velocity_dimensions == 1) {
//     if (space_dimensions == 1) {
//       return Dimensions_1D1V();
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
//       return Dimensions_1D2V();
//     } else if (space_dimensions == 2) {
//       return Dimensions_2D2V();
//     } else if (space_dimensions == 3) {
//       std::string message {"Invalid combination of space dimensions and velocity dimensions detected!"};
//       exit_with_failure(message);
//     } else {
//       exit_with_failure("space dimensions", space_dimensions);
//     }
//   } else if (velocity_dimensions == 3) {
//     if (space_dimensions == 1) {
//       return Dimensions_1D3V();
//     } else if (space_dimensions == 2) {
//       return Dimensions_2D3V();
//     } else if (space_dimensions == 3) {
//       return Dimensions_3D3V();
//     } else {
//       exit_with_failure("space dimensions", space_dimensions);
//     }
//   } else {
//     exit_with_failure("velocity dimensions", velocity_dimensions);
//   }
// }
