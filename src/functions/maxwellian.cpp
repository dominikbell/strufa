#include "maxwellian.hpp"

#include <cmath>

double maxwellian(double x, const Maxwellian_1D& maxwellian) {
  return maxwellian.amplitude * exp(-pow(x - maxwellian.shift, 2) / (2.0 * pow(maxwellian.temperature, 2))) / sqrt(2.0 * M_PI * pow(maxwellian.temperature, 2));
}
