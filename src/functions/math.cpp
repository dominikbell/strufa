#include "math.hpp"

#include <cmath>
#include <numbers>

// Sergei Winitzki's approximation (Fast and reasonably accurate). Source: Gemini
double erfinv_approx(double x) {
  const double a = 0.147;
  double l = std::log(1.0 - x * x);
  double b = (2.0 / (std::numbers::pi * a)) + (l / 2.0);
  double result = std::sqrt(std::sqrt(b * b - (l / a)) - b);
  return (x >= 0) ? result : -result;
}
