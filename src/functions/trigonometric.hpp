#pragma once

struct Space_Initial {};

struct Sine_1D {
  int wavenumber {0};
  double amplitude {0.0};
};

struct Cosine_1D {
  int wavenumber {0};
  double amplitude {0.0};
};

double sine(double x, const Sine_1D& sine_1D);
double cosine(double x, const Cosine_1D& cosine_1D);