#pragma once

#include <string>
#include <variant>

#include "io/input_parser.hpp"
#include "parameters/domain_parameters.hpp"
#include "utilities/dimensions.hpp"

template <typename TDimensions>
struct Cosine;

template <>
struct Cosine<D1> {
  int wavenumber {0};
  double amplitude {0.0};
  double domain_length {0.0};
};

template <>
struct Cosine<D2> {
  int wavenumber_x {0};
  int wavenumber_y {0};
  double amplitude {0.0};
  double domain_length_x {0.0};
  double domain_length_y {0.0};
};

template <>
struct Cosine<D3> {
  int wavenumber_x {0};
  int wavenumber_y {0};
  int wavenumber_z {0};
  double amplitude {0.0};
  double domain_length_x {0.0};
  double domain_length_y {0.0};
  double domain_length_z {0.0};
};

using CosineVariant = std::variant<
    Cosine<D1>,
    Cosine<D2>,
    Cosine<D3> >;

template <typename TDimensions>
inline Cosine<TDimensions> get_cosine(const json& function_data, const DomainParameters<TDimensions>& domain_parameters) {
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

double call_function(const Cosine<D1>& cosine, double x);
double call_function(const Cosine<D2>& cosine, double x, double y);
double call_function(const Cosine<D3>& cosine, double x, double y, double z);
double initialize_with_function(const Cosine<D1>& cosine, double x);
double initialize_with_function(const Cosine<D2>& cosine, double x, double y);
double initialize_with_function(const Cosine<D3>& cosine, double x, double y, double z);
