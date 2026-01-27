#include "feec_utilities.hpp"

#include <cassert>
#include <cmath>
#include <cstddef>
#include <vector>
#include "utilities/utilities.hpp"

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
    double dx = domain_length / static_cast<double>(n_points);
    for (size_t i = 1; i < n_points; ++i) {
      result.push_back(static_cast<double>(i) * dx);
    }
    return result;
  }
}

std::vector<double> make_knots(double domain_length, size_t n_points, int degree) {
  std::vector<double> result;

  // When the grid is empty, return empty knot vector
  if (n_points == 0) return result;

  result.reserve(n_points + static_cast<size_t>(degree));

  // dx is always the first entry
  const double dx {domain_length / static_cast<double>(n_points)};

  // Add elements in the ghost region
  for (size_t i = degree; i > 0; --i) {
    result.push_back(- static_cast<double>(i) * dx);
  }
  // Add left boundary of domain
  result.push_back(0.0);
  // Add points inside domain
  for (size_t i = 1; i < n_points; ++i) {
    result.push_back(static_cast<double>(i) * dx);
  }

  return result;
}

std::vector<double> make_grevilles(const std::vector<double>& knots, int degree) {
  std::vector<double> result;
  size_t grid_size {knots.size() + 1 - degree};
  result.reserve(grid_size);

  if (degree == 0) {
    exit_with_failure("To generate Greville points, the degree cannot be zero!");
  }

  double sum {};
  for (size_t ind = 1; ind < grid_size; ++ind) {
    sum = 0.0;
    for (size_t i = ind; i < ind + degree; ++i) {
      sum += knots[i];
    }
    result.push_back(sum / static_cast<double>(degree));
  }

  return result;
}

int find_span(double point, double grid_spacing, int degree) {
  return floor(point / grid_spacing) + degree;
}
