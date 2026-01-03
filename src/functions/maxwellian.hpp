#pragma once

#include <variant>

#include "utilities/dimensions.hpp"

template <typename Dimensions>
struct Maxwellian;

template <>
struct Maxwellian<D1> {
  double shift {0.0};
  double temperature {0.0};
  double amplitude {0.0};
};

template <>
struct Maxwellian<D2> {
  double shift_1 {0.0};
  double shift_2 {0.0};
  double temperature_1 {0.0};
  double temperature_2 {0.0};
  double amplitude {0.0};
};

template <>
struct Maxwellian<D3> {
  double shift_1 {0.0};
  double shift_2 {0.0};
  double shift_3 {0.0};
  double temperature_1 {0.0};
  double temperature_2 {0.0};
  double temperature_3 {0.0};
  double amplitude {0.0};
};

using MaxwellianVariant = std::variant<
    Maxwellian<D1>,
    Maxwellian<D2>,
    Maxwellian<D3> >;