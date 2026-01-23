#pragma once

#include <array>
#include <type_traits>
#include <variant>

#include "io/input_parser.hpp"
#include "utilities/dimensions.hpp"

template <typename TDimensions>
struct FiniteElementParameters {
  const std::array<int, TDimensions::space_dimensions> N_elements;
  const std::array<int, TDimensions::space_dimensions> degree;

  FiniteElementParameters(
      std::array<int, TDimensions::space_dimensions> N_elements_i,
      std::array<int, TDimensions::space_dimensions> degree_i)
      : N_elements(N_elements_i), degree(degree_i) {}
};

using FiniteElementParametersVariant = std::variant<
    FiniteElementParameters<D1>,
    FiniteElementParameters<D2>,
    FiniteElementParameters<D3> >;

template <typename TDimensions>
inline FiniteElementParameters<TDimensions> get_fe_parameters(const json& data) {
  assert_top_level_keyword(data, "FE");

  if constexpr (std::is_same_v<TDimensions, D1>) {
    assert_second_level_keyword(data, "FE", "N_elements");
    assert_second_level_keyword(data, "FE", "degree");

    int N_elements {data["FE"]["N_elements"]};
    int degree {data["FE"]["degree"]};

    return {{N_elements}, {degree}};
  } else if constexpr (std::is_same_v<TDimensions, D2>) {
    assert_second_level_keyword(data, "FE", "N_elements_x");
    assert_second_level_keyword(data, "FE", "N_elements_y");
    assert_second_level_keyword(data, "FE", "degree_x");
    assert_second_level_keyword(data, "FE", "degree_y");

    int N_elements_x {data["FE"]["N_elements_x"]};
    int N_elements_y {data["FE"]["N_elements_y"]};
    int degree_x {data["FE"]["degree_x"]};
    int degree_y {data["FE"]["degree_y"]};

    return {
        {N_elements_x, N_elements_y},
        {degree_x, degree_y},
    };
  } else if constexpr (std::is_same_v<TDimensions, D3>) {
    assert_second_level_keyword(data, "FE", "N_elements_x");
    assert_second_level_keyword(data, "FE", "N_elements_y");
    assert_second_level_keyword(data, "FE", "N_elements_z");
    assert_second_level_keyword(data, "FE", "degree_x");
    assert_second_level_keyword(data, "FE", "degree_y");
    assert_second_level_keyword(data, "FE", "degree_z");

    int N_elements_x {data["FE"]["N_elements_x"]};
    int N_elements_y {data["FE"]["N_elements_y"]};
    int N_elements_z {data["FE"]["N_elements_z"]};
    int degree_x {data["FE"]["degree_x"]};
    int degree_y {data["FE"]["degree_y"]};
    int degree_z {data["FE"]["degree_z"]};

    return {
        {N_elements_x, N_elements_y, N_elements_z},
        {degree_x, degree_y, degree_z}};
  }
}
