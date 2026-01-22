#include "cosine.hpp"

#include <cmath>
#include <numbers>

double call_function(const Cosine<D1>& cosine, double x) {
  double arg {cosine.wavenumber * x / cosine.domain_length};
  return cosine.amplitude * std::cos(2.0 * std::numbers::pi * arg);
}

double call_function(const Cosine<D2>& cosine, double x, double y) {
  double arg {cosine.wavenumber_x * x / cosine.domain_length_x +
              cosine.wavenumber_y * y / cosine.domain_length_y};
  return cosine.amplitude * std::cos(2.0 * std::numbers::pi * arg);
}
double call_function(const Cosine<D3>& cosine, double x, double y, double z) {
  double arg {cosine.wavenumber_x * x / cosine.domain_length_x +
              cosine.wavenumber_y * y / cosine.domain_length_y +
              cosine.wavenumber_z * z / cosine.domain_length_z};
  return cosine.amplitude * std::cos(2.0 * std::numbers::pi * arg);
}

double initialize_with_function(const Cosine<D1>& cosine, double x) {
  double arg {cosine.wavenumber * x / cosine.domain_length};
  return cosine.domain_length * cosine.amplitude * std::cos(2.0 * std::numbers::pi * arg);
}

double initialize_with_function(const Cosine<D2>& cosine, double x, double y) {
  double arg {cosine.wavenumber_x * x / cosine.domain_length_x +
              cosine.wavenumber_y * y / cosine.domain_length_y};
  return cosine.domain_length_x * cosine.domain_length_y *
         cosine.amplitude * std::cos(2.0 * std::numbers::pi * arg);
}
double initialize_with_function(const Cosine<D3>& cosine, double x, double y, double z) {
  double arg {cosine.wavenumber_x * x / cosine.domain_length_x +
              cosine.wavenumber_y * y / cosine.domain_length_y +
              cosine.wavenumber_z * z / cosine.domain_length_z};
  return cosine.domain_length_x * cosine.domain_length_y * cosine.domain_length_z *
         cosine.amplitude * std::cos(2.0 * std::numbers::pi * arg);
}
