#include "feec_utilities.hpp"

#include <cstddef>
#include <vector>
#include <cmath>

#include "utilities/utilities.hpp"

std::vector<double> make_grid(double length, size_t n_points, bool endpoint) {
  std::vector<double> result;

  // If no points are requested, return the empty vector
  if (n_points) return result;

  // Reserve the needed memory
  result.reserve(n_points);

  // The start (= 0.0 by default) is always the first point
  result.push_back(0.0);

  // Just one point means just the start which was already added
  if (n_points == 1) {
    return result;
  } else {
    if (endpoint) {
      // Have to compute inner points only if there are any
      if (n_points > 2) {
        double step = length / static_cast<double>(n_points - 1);
        for (size_t i = 1; i < n_points - 1; ++i) {
          result.push_back(static_cast<double>(i) * step);
        }
      }
      // Add the last point at the end and return result
      result.push_back(length);
      return result;
    } else {
      // Here the last point is not included so we have inner points already when n_points=2
      double step = length / static_cast<double>(n_points - 1);
      for (size_t i = 1; i < n_points - 1; ++i) {
        result.push_back(static_cast<double>(i) * step);
      }
      return result;
    }
  }
}

std::vector<double> make_knots(const std::vector<double>& grid_points, int degree) {
  // TODO: generalize for other degrees
  if (degree == 1) {
    std::vector<double> result;
    size_t grid_size {grid_points.size()};
    result.reserve(grid_size + static_cast<size_t>(2));
    result.push_back(-grid_points[1]);
    for (double grid_point : grid_points) {
      result.push_back(grid_point);
    }
    result.push_back(grid_points[grid_size - 1] + grid_points[1]);

    return result;
  } else {
    exit_with_failure("Spline degrees other than one are not implemented yet!");
  }
}

std::vector<double> make_grevilles(const std::vector<double>& knots, int degree) {
  // TODO: generalize for other degrees
  if (degree == 1) {
    std::vector<double> result;
    size_t grid_size {knots.size() - 1};
    result.reserve(grid_size);
    for (size_t ind = 1;  ind < grid_size; ++ind) {
      result.push_back(knots[ind]);
    }

    return result;
  } else {
    exit_with_failure("Spline degrees other than one are not implemented yet!");
  }
}

int find_span(double point, double grid_spacing, int degree) {
  return floor(point / grid_spacing) + degree;
}
