#pragma once

#include <array>
#include <cstddef>
#include <string>
#include <variant>

#include "io/input_parser.hpp"
#include "parameters/domain_parameters.hpp"
#include "utilities/dimensions.hpp"

template <typename TDimensions>
struct Sine {
  const std::array<int, TDimensions::space_dimensions> wavenumbers;
  const double amplitude;
  const std::array<double, TDimensions::space_dimensions> domain_sizes;

  Sine(
      std::array<int, TDimensions::space_dimensions> wavenumbers_i,
      double amplitude_i,
      std::array<double, TDimensions::space_dimensions> domain_sizes_i)
      : wavenumbers(wavenumbers_i),
        amplitude(amplitude_i),
        domain_sizes(domain_sizes_i) {}
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

    return {{function_data["wavenumber"]}, function_data["amplitude"], domain_parameters.domain_sizes};
  } else if constexpr (std::is_same_v<TDimensions, D2>) {
    assert_top_level_keyword(function_data, "wavenumber_x");
    assert_top_level_keyword(function_data, "wavenumber_y");
    assert_top_level_keyword(function_data, "amplitude");

    return {
        {function_data["wavenumber_x"],
         function_data["wavenumber_y"]},
        function_data["amplitude"],
        domain_parameters.domain_sizes};
  } else if constexpr (std::is_same_v<TDimensions, D3>) {
    assert_top_level_keyword(function_data, "wavenumber_x");
    assert_top_level_keyword(function_data, "wavenumber_y");
    assert_top_level_keyword(function_data, "wavenumber_z");
    assert_top_level_keyword(function_data, "amplitude");

    return {
        {function_data["wavenumber_x"],
         function_data["wavenumber_y"],
         function_data["wavenumber_z"]},
        function_data["amplitude"],
        domain_parameters.domain_sizes};
  }
}

double call_function(const Sine<D1>& sine, double x);
double call_function(const Sine<D2>& sine, double x, double y);
double call_function(const Sine<D3>& sine, double x, double y, double z);
double initialize_with_function(const Sine<D1>& sine, double x);
double initialize_with_function(const Sine<D2>& sine, double x, double y);
double initialize_with_function(const Sine<D3>& sine, double x, double y, double z);
