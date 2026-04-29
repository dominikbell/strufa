#include "matrices.hpp"

#include <cstddef>
#include <vector>

#include "feec_utilities.hpp"
#include "splines.hpp"

Circulant get_grad() {
  std::vector<double> entries {-1.0, 1.0};
  std::vector<size_t> cols {0, 1};
  return {entries, cols};
}

Circulant get_spline_collocation(size_t n_points, double grid_spacing) {
  std::vector<double> entries(1, 1.0);
  std::vector<size_t> cols(1, 0);

  return {entries, cols};
}

Circulant get_spline_histopolation(size_t n_points, double grid_spacing) {
  std::vector<double> entries(1, 1.0);
  std::vector<size_t> cols(1, 0);

  return {entries, cols};
}

Circulant get_mass_matrix_M0(size_t n_points, double grid_spacing) {
  std::vector<double> entries(1, grid_spacing);
  std::vector<size_t> cols(1, 0);

  return {entries, cols};
}

Circulant get_mass_matrix_M1(size_t n_points, double grid_spacing) {
  std::vector<double> entries(1, 1.0 / grid_spacing);
  std::vector<size_t> cols(1, 0);

  return {entries, cols};
}

Circulant get_spline_collocation(
    size_t n_points,
    int degree,
    double domain_length) {
  std::vector<double> entries(degree + 1, 0.0);
  std::vector<size_t> cols(degree + 1, 0);

  double grid_spacing {get_grid_spacing(domain_length, n_points)};

  double first_greville {get_first_greville(grid_spacing, degree)};
  int span {find_span(first_greville, grid_spacing, degree)};

  for (size_t col = 0; col < degree + 1; ++col) {
    // Have to add n_points here and then take the module because cpp modulo can be negative..
    cols[col] = static_cast<size_t>(span - degree) + col + n_points;
    cols[col] %= n_points;
  }
  eval_b_splines(first_greville, degree, span, grid_spacing, entries);

  return {entries, cols};
}

/** These are not correct!! */
// Circulant get_spline_histopolation(
//     size_t n_points,
//     int degree,
//     double domain_length) {
//   double grid_spacing {get_grid_spacing(domain_length, n_points)};

//   double first_greville {get_first_greville(grid_spacing, degree)};

//   if (degree > 1) {
//     first_greville += domain_length;
//   }

//   // Compute indices of the first and last non-zero spline
//   int j_max {degree + 1 / 2};
//   int j_min {std::max(0, j_max - degree)};
//   size_t size {static_cast<size_t>(j_max - j_min)};

//   std::vector<double> temporary(degree + 1, 0.0);

//   std::vector<double> entries {};
//   entries.reserve(size);
//   std::vector<size_t> cols {};
//   cols.reserve(size);

//   eval_b_splines(first_greville, degree, j_max, grid_spacing, temporary);

//   // Only degree many non-zero D-splines
//   for (size_t col = 0; col < degree + 1; ++col) {
//     entries.push_back(temporary[col]);
//     cols.push_back(static_cast<size_t>(j_min) + col);
//   }

//   return {entries, cols};
// }
