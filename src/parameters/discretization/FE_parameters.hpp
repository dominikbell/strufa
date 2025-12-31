#pragma once

#include <variant>

#include "io/input_parser.hpp"
#include "utilities/dimensions.hpp"

template <typename Dimensions>
struct FiniteElementParameters;

template <>
struct FiniteElementParameters<D1> {
  const int N_elements {0};
  const int degree {0};
};

template <>
struct FiniteElementParameters<D2> {
  const int N_elements_x {0};
  const int N_elements_y {0};
  const int degree_x {0};
  const int degree_y {0};
};

template <>
struct FiniteElementParameters<D3> {
  const int N_elements_x {0};
  const int N_elements_y {0};
  const int N_elements_z {0};
  const int degree_x {0};
  const int degree_y {0};
  const int degree_z {0};
};

using FiniteElementParametersVariant = std::variant<
    FiniteElementParameters<D1>,
    FiniteElementParameters<D2>,
    FiniteElementParameters<D3> >;

template <typename Dimensions>
inline FiniteElementParameters<Dimensions> get_fe_parameters(const json& data);

template <>
inline FiniteElementParameters<D1>
get_fe_parameters(const json& data) {
  assert_top_level_keyword(data, "FE");
  assert_second_level_keyword(data, "FE", "N_elements");
  assert_second_level_keyword(data, "FE", "degree");

  int N_elements {data["FE"]["N_elements"]};
  int degree {data["FE"]["degree"]};

  return {
      N_elements,
      degree};
}

template <>
inline FiniteElementParameters<D2>
get_fe_parameters(const json& data) {
  assert_top_level_keyword(data, "FE");
  assert_second_level_keyword(data, "FE", "N_elements_x");
  assert_second_level_keyword(data, "FE", "N_elements_y");
  assert_second_level_keyword(data, "FE", "degree_x");
  assert_second_level_keyword(data, "FE", "degree_y");

  int N_elements_x {data["FE"]["N_elements_x"]};
  int N_elements_y {data["FE"]["N_elements_y"]};
  int degree_x {data["FE"]["degree_x"]};
  int degree_y {data["FE"]["degree_y"]};

  return {
      N_elements_x,
      N_elements_y,
      degree_x,
      degree_y,
  };
}

template <>
inline FiniteElementParameters<D3>
get_fe_parameters(const json& data) {
  assert_top_level_keyword(data, "FE");
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
      N_elements_x,
      N_elements_y,
      N_elements_z,
      degree_x,
      degree_y,
      degree_z,
  };
}

FiniteElementParametersVariant get_fe_parameters(int space_dimensions, const json& data);