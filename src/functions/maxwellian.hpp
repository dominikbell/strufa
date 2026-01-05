#pragma once

#include <variant>

#include "io/input_parser.hpp"
#include "utilities/dimensions.hpp"

template <typename Dimensions>
struct Maxwellian;

template <>
struct Maxwellian<V1> {
  double shift {0.0};
  double temperature {0.0};
  double amplitude {0.0};
};

template <>
struct Maxwellian<V2> {
  double shift_1 {0.0};
  double shift_2 {0.0};
  double temperature_1 {0.0};
  double temperature_2 {0.0};
  double amplitude {0.0};
};

template <>
struct Maxwellian<V3> {
  double shift_1 {0.0};
  double shift_2 {0.0};
  double shift_3 {0.0};
  double temperature_1 {0.0};
  double temperature_2 {0.0};
  double temperature_3 {0.0};
  double amplitude {0.0};
};

using MaxwellianVariant = std::variant<
    Maxwellian<V1>,
    Maxwellian<V2>,
    Maxwellian<V3> >;

template <typename Dimensions>
inline Maxwellian<Dimensions> get_maxwellian(const json& data) {
  if constexpr (std::is_same_v<Dimensions, V1>) {
    assert_top_level_keyword(data, "shift");
    assert_top_level_keyword(data, "temperature");
    assert_top_level_keyword(data, "amplitude");

    return {
        data["shift"],
        data["temperature"],
        data["amplitude"]};
  } else if constexpr (std::is_same_v<Dimensions, V2>) {
    assert_top_level_keyword(data, "shift_1");
    assert_top_level_keyword(data, "shift_2");
    assert_top_level_keyword(data, "temperature_1");
    assert_top_level_keyword(data, "temperature_2");
    assert_top_level_keyword(data, "amplitude");

    return {
        data["shift_1"],
        data["shift_2"],
        data["temperature_1"],
        data["temperature_2"],
        data["amplitude"]};

  } else if constexpr (std::is_same_v<Dimensions, V3>) {
    assert_top_level_keyword(data, "shift_1");
    assert_top_level_keyword(data, "shift_2");
    assert_top_level_keyword(data, "shift_3");
    assert_top_level_keyword(data, "temperature_1");
    assert_top_level_keyword(data, "temperature_2");
    assert_top_level_keyword(data, "temperature_3");
    assert_top_level_keyword(data, "amplitude");

    return {
        data["shift_1"],
        data["shift_2"],
        data["shift_3"],
        data["temperature_1"],
        data["temperature_2"],
        data["temperature_3"],
        data["amplitude"]};
  }
}

MaxwellianVariant get_maxwellian(int velocity_dimensions, const json& data);
