#pragma once

#include <variant>

#include "io/input_parser.hpp"
#include "utilities/dimensions.hpp"

template <typename Dimensions>
struct DomainParameters;

template <>
struct DomainParameters<D1> {
  const double domain_length {0.0};
};

template <>
struct DomainParameters<D2> {
  const double domain_size_x {0.0};
  const double domain_size_y {0.0};
};

using DomainParametersVariant = std::variant<
    DomainParameters<D1>,
    DomainParameters<D2> >;


template <typename Dimensions>
inline DomainParameters<Dimensions> get_domain_parameters(const json& data) {
  assert_top_level_keyword(data, "domain");

  if constexpr (std::is_same_v<Dimensions, D1>) {
    assert_second_level_keyword(data, "domain", "length");

    double domain_length {data["domain"]["length"]};

    return {domain_length};
  } else if constexpr (std::is_same_v<Dimensions, D2>) {
    assert_second_level_keyword(data, "domain", "size_x");
    assert_second_level_keyword(data, "domain", "size_y");

    double domain_size_x {data["domain"]["size_x"]};
    double domain_size_y {data["domain"]["size_y"]};

    return {domain_size_x, domain_size_y};
  }
}

DomainParametersVariant get_domain_parameters(int space_dimensions, const json& data);
