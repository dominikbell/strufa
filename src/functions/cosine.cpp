#include "cosine.hpp"

#include <cmath>
#include <numbers>

double call_function(const Cosine<D1>& cosine, double x) {
  double arg {cosine.wavenumbers[0] * x / cosine.domain_sizes[0]};
  return cosine.amplitude * std::cos(2.0 * std::numbers::pi * arg);
}

double call_function(const Cosine<D2>& cosine, double x, double y) {
  double arg {cosine.wavenumbers[0] * x / cosine.domain_sizes[0] +
              cosine.wavenumbers[1] * y / cosine.domain_sizes[1]};
  return cosine.amplitude * std::cos(2.0 * std::numbers::pi * arg);
}
double call_function(const Cosine<D3>& cosine, double x, double y, double z) {
  double arg {cosine.wavenumbers[0] * x / cosine.domain_sizes[0] +
              cosine.wavenumbers[1] * y / cosine.domain_sizes[1] +
              cosine.wavenumbers[2] * z / cosine.domain_sizes[2]};
  return cosine.amplitude * std::cos(2.0 * std::numbers::pi * arg);
}

double initialize_with_function(const Cosine<D1>& cosine, double x) {
  double arg {cosine.wavenumbers[0] * x / cosine.domain_sizes[0]};
  return cosine.domain_sizes[0] * cosine.amplitude * std::cos(2.0 * std::numbers::pi * arg);
}

double initialize_with_function(const Cosine<D2>& cosine, double x, double y) {
  double arg {cosine.wavenumbers[0] * x / cosine.domain_sizes[0] +
              cosine.wavenumbers[1] * y / cosine.domain_sizes[1]};
  return cosine.domain_sizes[0] * cosine.domain_sizes[1] *
         cosine.amplitude * std::cos(2.0 * std::numbers::pi * arg);
}
double initialize_with_function(const Cosine<D3>& cosine, double x, double y, double z) {
  double arg {cosine.wavenumbers[0] * x / cosine.domain_sizes[0] +
              cosine.wavenumbers[1] * y / cosine.domain_sizes[1] +
              cosine.wavenumbers[2] * z / cosine.domain_sizes[2]};
  return cosine.domain_sizes[0] * cosine.domain_sizes[1] * cosine.domain_sizes[2] *
         cosine.amplitude * std::cos(2.0 * std::numbers::pi * arg);
}
