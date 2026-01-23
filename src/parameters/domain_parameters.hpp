#pragma once

#include <array>

#include "io/input_parser.hpp"
#include "utilities/dimensions.hpp"

template <typename TDimensions>
struct DomainParameters {
  const std::array<double, TDimensions::space_dimensions> domain_sizes;

  DomainParameters(
      std::array<double, TDimensions::space_dimensions> domain_sizes_i)
      : domain_sizes(domain_sizes_i) {}
};

template <typename TDimensions>
inline DomainParameters<TDimensions> get_domain_parameters(const json& data) {
  assert_top_level_keyword(data, "domain");

  if constexpr (std::is_same_v<TDimensions, D1>) {
    assert_second_level_keyword(data, "domain", "size");

    double domain_size {data["domain"]["size"]};

    return {{domain_size}};
  } else if constexpr (std::is_same_v<TDimensions, D2>) {
    assert_second_level_keyword(data, "domain", "size_x");
    assert_second_level_keyword(data, "domain", "size_y");

    double domain_size_x {data["domain"]["size_x"]};
    double domain_size_y {data["domain"]["size_y"]};

    return {{domain_size_x, domain_size_y}};
  } else if constexpr (std::is_same_v<TDimensions, D3>) {
    assert_second_level_keyword(data, "domain", "size_x");
    assert_second_level_keyword(data, "domain", "size_y");
    assert_second_level_keyword(data, "domain", "size_z");

    double domain_size_x {data["domain"]["size_x"]};
    double domain_size_y {data["domain"]["size_y"]};
    double domain_size_z {data["domain"]["size_z"]};

    return {{domain_size_x, domain_size_y, domain_size_z}};
  }
}
