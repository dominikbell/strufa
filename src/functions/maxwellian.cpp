#include "maxwellian.hpp"

#include <cmath>
#include <numbers>

double call_function(const Maxwellian<V1>& maxwellian, double v1) {
  double arg {std::pow(v1 - maxwellian.shift[0], 2) / (2.0 * std::pow(maxwellian.temperature[0], 2))};
  double factor {1.0 / std::sqrt(2.0 * std::numbers::pi * std::pow(maxwellian.temperature[0], 2))};
  return maxwellian.amplitude * factor * std::exp((-1.0) * arg);
}

double call_function(const Maxwellian<V2>& maxwellian, double v1, double v2) {
  double arg {std::pow(v1 - maxwellian.shift[0], 2) / (2.0 * std::pow(maxwellian.temperature[0], 2)) +
              std::pow(v2 - maxwellian.shift[1], 2) / (2.0 * std::pow(maxwellian.temperature[1], 2))};
  double factor {1.0 / std::sqrt(std::pow(2.0 * std::numbers::pi, 2) *
                                 std::pow(maxwellian.temperature[0], 2) *
                                 std::pow(maxwellian.temperature[1], 2))};
  return maxwellian.amplitude * factor * std::exp((-1.0) * arg);
}

double call_function(const Maxwellian<V3>& maxwellian, double v1, double v2, double v3) {
  double arg {std::pow(v1 - maxwellian.shift[0], 2) / (2.0 * std::pow(maxwellian.temperature[0], 2)) +
              std::pow(v2 - maxwellian.shift[1], 2) / (2.0 * std::pow(maxwellian.temperature[1], 2)) +
              std::pow(v3 - maxwellian.shift[2], 2) / (2.0 * std::pow(maxwellian.temperature[2], 2))};
  double factor {1.0 / std::sqrt(std::pow(2.0 * std::numbers::pi, 3) *
                                 std::pow(maxwellian.temperature[0], 2) *
                                 std::pow(maxwellian.temperature[1], 2) *
                                 std::pow(maxwellian.temperature[2], 2))};
  return maxwellian.amplitude * factor * std::exp((-1.0) * arg);
}
