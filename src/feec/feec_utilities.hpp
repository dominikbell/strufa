#pragma once

#include <array>
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

std::vector<double> make_grid(double length, size_t n_points);
std::vector<double> make_knots(double domain_length, size_t n_points, int degree);
std::vector<double> make_grevilles(const std::vector<double>& knots, int degree);

inline int find_span(double point, double grid_spacing, int degree) {
  return floor(point / grid_spacing) + degree;
}
