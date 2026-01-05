#pragma once

#include <string>
#include <variant>

#include "io/input_parser.hpp"
#include "utilities/dimensions.hpp"

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

template <typename Dimensions>
inline Cosine<Dimensions> get_cosine(const json& data) {
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

CosineVariant get_cosine(int space_dimensions, const json& data);
