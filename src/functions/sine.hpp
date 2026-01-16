#pragma once

#include <cstddef>
#include <string>
#include <variant>

#include "io/input_parser.hpp"
#include "utilities/dimensions.hpp"

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
inline Sine<Dimensions> get_sine(const json& data) {
  if constexpr (std::is_same_v<Dimensions, D1>) {
    assert_top_level_keyword(data, "wavenumber");
    assert_top_level_keyword(data, "amplitude");

    return {data["wavenumber"], data["amplitude"]};
  } else if constexpr (std::is_same_v<Dimensions, D2>) {
    assert_top_level_keyword(data, "wavenumber_x");
    assert_top_level_keyword(data, "wavenumber_y");
    assert_top_level_keyword(data, "amplitude");

    return {
        data["wavenumber_x"],
        data["wavenumber_y"],
        data["amplitude"]};
  } else if constexpr (std::is_same_v<Dimensions, D3>) {
    assert_top_level_keyword(data, "wavenumber_x");
    assert_top_level_keyword(data, "wavenumber_y");
    assert_top_level_keyword(data, "wavenumber_z");
    assert_top_level_keyword(data, "amplitude");

    return {
        data["wavenumber_x"],
        data["wavenumber_y"],
        data["wavenumber_z"],
        data["amplitude"]};
  }
}

SineVariant get_sine(int space_dimensions, const json& data);

double call_function(const Sine<D1>& sine_1D, double x);
double call_function(const Sine<D2>& sine_2D, double x, double y);
double call_function(const Sine<D3>& sine_3D, double x, double y, double z);
