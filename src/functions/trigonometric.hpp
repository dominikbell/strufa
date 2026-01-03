#pragma once

#include <string>
#include <utility>
#include <variant>

#include "utilities/dimensions.hpp"
#include "utilities/utilities.hpp"

template <typename Dimensions>
struct Sine;

template <>
struct Sine<D1> {
  int wavenumber {0};
  double amplitude {0.0};
};

template <>
struct Sine<D2> {
  int wavenumber_x {0};
  int wavenumber_y {0};
  double amplitude {0.0};
};

template <>
struct Sine<D3> {
  int wavenumber_x {0};
  int wavenumber_y {0};
  int wavenumber_z {0};
  double amplitude {0.0};
};

using SineVariant = std::variant<
    Sine<D1>,
    Sine<D2>,
    Sine<D3> >;

template <typename Dimensions>
inline Sine<Dimensions> get_sine(const std::string& str) {
  // if constexpr (std::is_same_v<Dimensions, D1>) {
  //   assert_second_level_keyword(data, "")
  // }
}

template <typename Dimensions>
struct Cosine;

template <>
struct Cosine<D1> {
  int wavenumber {0};
  double amplitude {0.0};
};

template <>
struct Cosine<D2> {
  int wavenumber_x {0};
  int wavenumber_y {0};
  double amplitude {0.0};
};

template <>
struct Cosine<D3> {
  int wavenumber_x {0};
  int wavenumber_y {0};
  int wavenumber_z {0};
  double amplitude {0.0};
};

using CosineVariant = std::variant<
    Cosine<D1>,
    Cosine<D2>,
    Cosine<D3> >;

// template <typename Dimensions>
// double sine(double x, const Sine<Dimensions> sine);

// double sine(std::pair<int, int> pair_dimensions, double x);
