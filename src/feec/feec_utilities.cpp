#include "feec_utilities.hpp"

#include <cassert>

std::vector<double> make_grid(double domain_length, size_t n_points) {
  std::vector<double> result;

  // If no points are requested, return the empty vector
  if (n_points == 0) return result;

  // Reserve the needed memory
  result.reserve(n_points);

  // The start (= 0.0 by default) is always the first point
  result.push_back(0.0);

  // Just one point means just the start which was already added
  if (n_points == 1) {
    return result;
  } else {
    double grid_spacing = domain_length / static_cast<double>(n_points);
    for (size_t i = 1; i < n_points; ++i) {
      result.push_back(static_cast<double>(i) * grid_spacing);
    }
    return result;
  }
}

std::vector<double> make_knots(double grid_spacing, size_t n_points, int degree) {
  std::vector<double> result;

  // When the grid is empty, return empty knot vector
  if (n_points == 0) return result;

  // Reserve the needed memory
  result.reserve(n_points + static_cast<size_t>(degree));

  // Add elements in the ghost region
  for (size_t i = degree; i > 0; --i) {
    result.push_back(- static_cast<double>(i) * grid_spacing);
  }
  // Add left boundary of domain manually to avoid numerical artifacts
  result.push_back(0.0);
  // Add points inside domain
  for (size_t i = 1; i < n_points; ++i) {
    result.push_back(static_cast<double>(i) * grid_spacing);
  }

  return result;
}

std::vector<double> make_grevilles(double grid_spacing, size_t n_points, int degree) {
  std::vector<double> result;

  // When the grid is empty, return empty vector
  if (n_points == 0) return result;

  result.reserve(n_points);

  double offset {grid_spacing * (1.0 - static_cast<double>(degree)) / 2.0 };
  for (size_t ind = 0; ind < n_points; ++ind) {
    result.push_back(static_cast<double>(ind) * grid_spacing + offset);
  }

  return result;
}
