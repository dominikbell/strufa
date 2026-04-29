#pragma once

#include <array>
#include <cmath>
#include <cstddef>
#include <vector>

#include "parameters/discretization/FE_parameters.hpp"
#include "parameters/domain_parameters.hpp"

template <typename TDimensions>
std::array<std::vector<double>, TDimensions::space_dimensions> make_grid(
    const DomainParameters<TDimensions>& domain_parameters,
    const FiniteElementParameters<TDimensions>& fe_parameters) {
  constexpr int dimensions {TDimensions::space_dimensions};
  std::array<std::vector<double>, TDimensions::space_dimensions> result;

  for (int dim = 0; dim < dimensions; ++dim) {
    result[dim] = make_grid(
        domain_parameters.domain_sizes[dim],
        static_cast<size_t>(fe_parameters.N_elements[dim]),
        false);
  }
}

std::vector<double> make_grid(double domain_length, size_t n_points);
std::vector<double> make_knots(double domain_length, size_t n_points, int degree);
std::vector<double> make_grevilles(double grid_spacing, size_t n_points, int degree);

inline double get_grid_spacing(double domain_length, size_t n_points) {
  return domain_length / static_cast<double>(n_points);
}

inline double get_knot_of_index(double grid_spacing, int degree, size_t index) {
  return grid_spacing * (static_cast<double>(index) - static_cast<double>(degree));
}

inline double get_first_greville(double grid_spacing, int degree) {
  return grid_spacing * (1.0 - static_cast<double>(degree)) / 2.0;
}

inline double get_greville_of_index(double grid_spacing, int degree, size_t index) {
  return grid_spacing * (static_cast<double>(index) + (1.0 - static_cast<double>(degree)) / 2.0);
}

inline int find_span(double point, double grid_spacing, int degree) {
  return static_cast<int>(floor(point / grid_spacing)) + degree;
}
