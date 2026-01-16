#include "sine.hpp"

#include <cmath>

SineVariant get_sine(int space_dimensions, const json& data) {
  SpaceDimensionsVariant space_dims {get_space_dimensions(space_dimensions)};

  return std::visit(
      [&](auto& dim) -> SineVariant {
        using Dim = std::decay_t<decltype(dim)>;
        return get_sine<Dim>(data);
      },
      space_dims);
}

double call_function(const Sine<D1>& sine_1D, double x) {
  return sine_1D.amplitude * sin(sine_1D.wavenumber * x);
}

double call_function(const Sine<D2>& sine_2D, double x, double y) {
  return sine_2D.amplitude * sin(sine_2D.wavenumber_x * x + sine_2D.wavenumber_y * y);
}
double call_function(const Sine<D3>& sine_3D, double x, double y, double z) {
  return sine_3D.amplitude * sin(sine_3D.wavenumber_x * x + sine_3D.wavenumber_y * y + sine_3D.wavenumber_z * z);
}
