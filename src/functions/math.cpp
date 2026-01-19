#include "math.hpp"

#include <cmath>
#include <iostream>
#include <numbers>

// Sergei Winitzki's approximation (Fast and reasonably accurate). Source: Gemini
double erfinv_approx(double x) {
  const double a = 0.147;
  double l = std::log(1.0 - x * x);
  double b = (2.0 / (std::numbers::pi * a)) + (l / 2.0);
  double result = std::sqrt(std::sqrt(b * b - (l / a)) - b);
  std::cout << "x = " << x << "\t result = " << result << '\n';
  return (x >= 0) ? result : -result;
}
