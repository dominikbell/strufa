#include "splines.hpp"

#include <array>
#include <cstddef>

#include "main.hpp"

/**
 * Evaluate the (degree+1) non-zero B-spline basis functions at a point
 *
 * output must have p+1 entries
 */
void eval_b_splines(
    double point,
    int degree,
    int span,
    double grid_spacing,
    std::vector<double>& output) {
  // Zero-initialize temporary memory on the stack
  std::array<double, MAX_DEGREE + 2> splines_temp {};
  splines_temp[MAX_DEGREE] = 1.0;

  // Transform the point into the first cell of the domain
  double first_point {point - static_cast<double>(span - degree) * grid_spacing};

  double weight_j {};
  double weight_jp1 {};
  size_t ind_j {};
  for (size_t k = 1; k < degree + 1; ++k) {
    for (size_t j = degree - k; j < degree + 1; ++j) {
      // Make the index to navigate in the larger table
      ind_j = MAX_DEGREE - degree + j;
      // Compute the weights for the same and next index
      weight_j = (first_point / grid_spacing + static_cast<double>(degree - static_cast<int>(j))) / static_cast<double>(k);
      weight_jp1 = (static_cast<double>(static_cast<int>(j + k) + 1 - degree) - first_point / grid_spacing) / static_cast<double>(k);
      splines_temp[ind_j] = weight_j * splines_temp[ind_j] + weight_jp1 * splines_temp[ind_j + 1];
    }
  }

  // Copy the result in the output vector
  for (size_t j = 0; j < degree + 1; ++j) {
    output[j] = splines_temp[MAX_DEGREE - degree + j];
  }
}

void eval_d_splines(
    double point,
    int degree,
    int span,
    double grid_spacing,
    std::vector<double>& output) {
  eval_b_splines(point, degree - 1, span - 1, grid_spacing, output);
  for (auto& out : output) {
    out /= grid_spacing;
  }
}

void eval_b_d_splines(
    double point,
    int degree,
    int span,
    double grid_spacing,
    std::vector<double>& output_b,
    std::vector<double>& output_d) {
  eval_b_splines(point, degree, span, grid_spacing, output_b);
  eval_d_splines(point, degree, span, grid_spacing, output_d);
}
