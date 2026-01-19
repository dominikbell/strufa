#include "sine.hpp"

#include <cmath>
#include <numbers>

SineVariant get_sine(const json& data, const DomainParametersVariant& domain_parameters) {
  return std::visit(
      [&](auto& domain_params) -> SineVariant {
        using Dim = GetFirstInnerType_t<decltype(domain_params)>;
        return get_sine<Dim>(data, domain_params);
      },
      domain_parameters);
}

double call_function(const Sine<D1>& sine, double x) {
  double arg {sine.wavenumber * x / sine.domain_length};
  return sine.amplitude * std::sin(2.0 * std::numbers::pi * arg);
}

double call_function(const Sine<D2>& sine, double x, double y) {
  double arg {sine.wavenumber_x * x / sine.domain_length_x +
              sine.wavenumber_y * y / sine.domain_length_y};
  return sine.amplitude * std::sin(2.0 * std::numbers::pi * arg);
}
double call_function(const Sine<D3>& sine, double x, double y, double z) {
  double arg {sine.wavenumber_x * x / sine.domain_length_x +
              sine.wavenumber_y * y / sine.domain_length_y +
              sine.wavenumber_z * z / sine.domain_length_z};
  return sine.amplitude * std::sin(2.0 * std::numbers::pi * arg);
}

double initialize_with_function(const Sine<D1>& sine, double x) {
  double arg {sine.wavenumber * x / sine.domain_length};
  return sine.domain_length * sine.amplitude * std::sin(2.0 * std::numbers::pi * arg);
}

double initialize_with_function(const Sine<D2>& sine, double x, double y) {
  double arg {sine.wavenumber_x * x / sine.domain_length_x +
              sine.wavenumber_y * y / sine.domain_length_y};
  return sine.domain_length_x * sine.domain_length_y * sine.amplitude *
         std::sin(2.0 * std::numbers::pi * arg);
}
double initialize_with_function(const Sine<D3>& sine, double x, double y, double z) {
  double arg {sine.wavenumber_x * x / sine.domain_length_x +
              sine.wavenumber_y * y / sine.domain_length_y +
              sine.wavenumber_z * z / sine.domain_length_z};
  return sine.domain_length_x * sine.domain_length_y * sine.domain_length_z *
         sine.amplitude * std::sin(2.0 * std::numbers::pi * arg);
}
