#include "sine.hpp"

#include <cmath>
#include <numbers>

double call_function(const Sine<D1>& sine, double x) {
  double arg {sine.wavenumbers[0] * x / sine.domain_sizes[0]};
  return sine.amplitude * std::sin(2.0 * std::numbers::pi * arg);
}

double call_function(const Sine<D2>& sine, double x, double y) {
  double arg {sine.wavenumbers[0] * x / sine.domain_sizes[0] +
              sine.wavenumbers[1] * y / sine.domain_sizes[1]};
  return sine.amplitude * std::sin(2.0 * std::numbers::pi * arg);
}
double call_function(const Sine<D3>& sine, double x, double y, double z) {
  double arg {sine.wavenumbers[0] * x / sine.domain_sizes[0] +
              sine.wavenumbers[1] * y / sine.domain_sizes[1] +
              sine.wavenumbers[2] * z / sine.domain_sizes[2]};
  return sine.amplitude * std::sin(2.0 * std::numbers::pi * arg);
}

double initialize_with_function(const Sine<D1>& sine, double x) {
  double arg {sine.wavenumbers[0] * x / sine.domain_sizes[0]};
  return sine.domain_sizes[0] * sine.amplitude * std::sin(2.0 * std::numbers::pi * arg);
}

double initialize_with_function(const Sine<D2>& sine, double x, double y) {
  double arg {sine.wavenumbers[0] * x / sine.domain_sizes[0] +
              sine.wavenumbers[1] * y / sine.domain_sizes[1]};
  return sine.domain_sizes[0] * sine.domain_sizes[1] * sine.amplitude *
         std::sin(2.0 * std::numbers::pi * arg);
}
double initialize_with_function(const Sine<D3>& sine, double x, double y, double z) {
  double arg {sine.wavenumbers[0] * x / sine.domain_sizes[0] +
              sine.wavenumbers[1] * y / sine.domain_sizes[1] +
              sine.wavenumbers[2] * z / sine.domain_sizes[2]};
  return sine.domain_sizes[0] * sine.domain_sizes[1] * sine.domain_sizes[2] *
         sine.amplitude * std::sin(2.0 * std::numbers::pi * arg);
}
