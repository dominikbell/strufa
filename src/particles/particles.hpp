#pragma once

#include <vector>

struct Particles_1D1V {
  std::vector<double> positions_x;
  std::vector<double> velocities_x;

  Particles_1D1V(long N_markers) : positions_x(N_markers),
                                   velocities_x(N_markers) {}
};

struct Particles_1D2V {
  std::vector<double> positions_x;
  std::vector<double> velocities_x;
  std::vector<double> velocities_y;

  Particles_1D2V(long N_markers) : positions_x(N_markers),
                                   velocities_x(N_markers),
                                   velocities_y(N_markers) {}
};