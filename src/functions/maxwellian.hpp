#pragma once

struct Maxwellian_1D {
  double shift {0.0};
  double temperature {0.0};
  double amplitude {0.0};
};

double maxwellian(double x, Maxwellian_1D& maxwellian);