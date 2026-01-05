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

// double sine(double x, const Sine_1D& sine_1D) {
//   return sine_1D.amplitude * sin(sine_1D.wavenumber * x);
// }
