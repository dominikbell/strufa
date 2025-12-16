#include "parameters/parameters_advection.hpp"
#include "vvariables/variables_advection.hpp"
#include "particles/sample.hpp"

Variables_Advection_1D1V setup_advection(const Parameters_Advection_1D1V& parameters) {
  Variables_Advection_1D1V variables {parameters.N_markers, parameters.seed};
  sample_particles(variables.particles);
  return variables;
}