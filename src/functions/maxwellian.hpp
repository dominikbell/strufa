#pragma once

#include <cassert>
#include <variant>

#include "functions/math.hpp"
#include "io/input_parser.hpp"
#include "utilities/dimensions.hpp"

template <typename Dimensions>
struct Maxwellian {
  const double amplitude;
  const double shift[Dimensions::velocity_dimensions];
  const double temperature[Dimensions::velocity_dimensions];
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
    assert_keyword_not_zero(data, "temperature");
    assert_top_level_keyword(data, "amplitude");
    assert_keyword_not_zero(data, "amplitude");
    return {
        data["amplitude"],
        {data["shift"]},
        {data["temperature"]}};
  } else if constexpr (std::is_same_v<Dimensions, V2>) {
    assert_top_level_keyword(data, "shift_1");
    assert_top_level_keyword(data, "shift_2");
    assert_top_level_keyword(data, "temperature_1");
    assert_keyword_not_zero(data, "temperature_1");
    assert_top_level_keyword(data, "temperature_2");
    assert_keyword_not_zero(data, "temperature_2");
    assert_top_level_keyword(data, "amplitude");
    assert_keyword_not_zero(data, "amplitude");

    return {
        data["amplitude"],
        {data["shift_1"],
         data["shift_2"]},
        {data["temperature_1"],
         data["temperature_2"]}};

  } else if constexpr (std::is_same_v<Dimensions, V3>) {
    assert_top_level_keyword(data, "shift_1");
    assert_top_level_keyword(data, "shift_2");
    assert_top_level_keyword(data, "shift_3");
    assert_top_level_keyword(data, "temperature_1");
    assert_keyword_not_zero(data, "temperature_1");
    assert_top_level_keyword(data, "temperature_2");
    assert_keyword_not_zero(data, "temperature_2");
    assert_top_level_keyword(data, "temperature_3");
    assert_keyword_not_zero(data, "temperature_3");
    assert_top_level_keyword(data, "amplitude");
    assert_keyword_not_zero(data, "amplitude");

    return {
        data["amplitude"],
        {data["shift_1"],
         data["shift_2"],
         data["shift_3"]},
        {data["temperature_1"],
         data["temperature_2"],
         data["temperature_3"]}};
  }
}

MaxwellianVariant get_maxwellian(int velocity_dimensions, const json& data);

template <typename Dimensions>
double initialize_with_function(const Maxwellian<Dimensions>& maxwellian, const int index, double v) {
  double arg {2.0 * v / maxwellian.amplitude - 1.0};
  return std::sqrt(2.0 * std::pow(maxwellian.temperature[index], 2)) *
             erfinv_approx(arg) +
         maxwellian.shift[index];
}
