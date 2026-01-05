#include "maxwellian.hpp"

#include <cmath>

MaxwellianVariant get_maxwellian(int velocity_dimensions, const json& data) {
  VelocityDimensionsVariant velocity_dims {get_velocity_dimensions(velocity_dimensions)};

  return std::visit(
      [&](auto& dim) -> MaxwellianVariant {
        using Dim = std::decay_t<decltype(dim)>;
        return get_maxwellian<Dim>(data);
      },
      velocity_dims);
}

// double maxwellian(double x, const Maxwellian_1D& maxwellian) {
//   return maxwellian.amplitude * exp(-pow(x - maxwellian.shift, 2) / (2.0 * pow(maxwellian.temperature, 2))) / sqrt(2.0 * M_PI * pow(maxwellian.temperature, 2));
// }
