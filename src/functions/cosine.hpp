#pragma once

#include <string>
#include <variant>

#include "io/input_parser.hpp"
#include "parameters/domain_parameters.hpp"
#include "utilities/dimensions.hpp"

template <typename TDimensions>
struct Cosine {
  const std::array<int, TDimensions::space_dimensions> wavenumbers;
  const double amplitude;
  const std::array<double, TDimensions::space_dimensions> domain_sizes;

  Cosine(
      std::array<int, TDimensions::space_dimensions> wavenumbers_i,
      double amplitude_i,
      std::array<double, TDimensions::space_dimensions> domain_sizes_i)
      : wavenumbers(wavenumbers_i),
        amplitude(amplitude_i),
        domain_sizes(domain_sizes_i) {}
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

    return {{function_data["wavenumber"]}, function_data["amplitude"], domain_parameters.domain_sizes};
  } else if constexpr (std::is_same_v<TDimensions, D2>) {
    assert_top_level_keyword(function_data, "wavenumber_x");
    assert_top_level_keyword(function_data, "wavenumber_y");
    assert_top_level_keyword(function_data, "amplitude");

    return {
        {function_data["wavenumber_x"], function_data["wavenumber_y"]},
        function_data["amplitude"],
        domain_parameters.domain_sizes};
  } else if constexpr (std::is_same_v<TDimensions, D3>) {
    assert_top_level_keyword(function_data, "wavenumber_x");
    assert_top_level_keyword(function_data, "wavenumber_y");
    assert_top_level_keyword(function_data, "wavenumber_z");
    assert_top_level_keyword(function_data, "amplitude");

    return {
        {function_data["wavenumber_x"], function_data["wavenumber_y"], function_data["wavenumber_z"]},
        function_data["amplitude"],
        domain_parameters.domain_sizes};
  }
}

double call_function(const Cosine<D1>& cosine, double x);
double call_function(const Cosine<D2>& cosine, double x, double y);
double call_function(const Cosine<D3>& cosine, double x, double y, double z);
double initialize_with_function(const Cosine<D1>& cosine, double x);
double initialize_with_function(const Cosine<D2>& cosine, double x, double y);
double initialize_with_function(const Cosine<D3>& cosine, double x, double y, double z);
