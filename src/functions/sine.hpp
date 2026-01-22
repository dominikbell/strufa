#pragma once

#include <cstddef>
#include <string>
#include <variant>

#include "io/input_parser.hpp"
#include "parameters/domain_parameters.hpp"
#include "utilities/dimensions.hpp"

template <typename TDimensions>
struct Sine;

template <>
struct Sine<D1> {
  int wavenumber {0};
  double amplitude {0.0};
  double domain_length {0.0};
};

template <>
struct Sine<D2> {
  int wavenumber_x {0};
  int wavenumber_y {0};
  double amplitude {0.0};
  double domain_length_x {0.0};
  double domain_length_y {0.0};
};

template <>
struct Sine<D3> {
  int wavenumber_x {0};
  int wavenumber_y {0};
  int wavenumber_z {0};
  double amplitude {0.0};
  double domain_length_x {0.0};
  double domain_length_y {0.0};
  double domain_length_z {0.0};
};

using SineVariant = std::variant<
    Sine<D1>,
    Sine<D2>,
    Sine<D3> >;

template <typename TDimensions>
inline Sine<TDimensions> get_sine(const json& function_data, const DomainParameters<TDimensions>& domain_parameters) {
  if constexpr (std::is_same_v<TDimensions, D1>) {
    assert_top_level_keyword(function_data, "wavenumber");
    assert_top_level_keyword(function_data, "amplitude");

    return {function_data["wavenumber"], function_data["amplitude"], domain_parameters.domain_length};
  } else if constexpr (std::is_same_v<TDimensions, D2>) {
    assert_top_level_keyword(function_data, "wavenumber_x");
    assert_top_level_keyword(function_data, "wavenumber_y");
    assert_top_level_keyword(function_data, "amplitude");

    return {
        function_data["wavenumber_x"],
        function_data["wavenumber_y"],
        function_data["amplitude"],
        domain_parameters.domain_size_x,
        domain_parameters.domain_size_y};
  } else if constexpr (std::is_same_v<TDimensions, D3>) {
    assert_top_level_keyword(function_data, "wavenumber_x");
    assert_top_level_keyword(function_data, "wavenumber_y");
    assert_top_level_keyword(function_data, "wavenumber_z");
    assert_top_level_keyword(function_data, "amplitude");

    return {
        function_data["wavenumber_x"],
        function_data["wavenumber_y"],
        function_data["wavenumber_z"],
        function_data["amplitude"],
        domain_parameters.domain_size_x,
        domain_parameters.domain_size_y,
        domain_parameters.domain_size_z};
  }
}

double call_function(const Sine<D1>& sine, double x);
double call_function(const Sine<D2>& sine, double x, double y);
double call_function(const Sine<D3>& sine, double x, double y, double z);
double initialize_with_function(const Sine<D1>& sine, double x);
double initialize_with_function(const Sine<D2>& sine, double x, double y);
double initialize_with_function(const Sine<D3>& sine, double x, double y, double z);
