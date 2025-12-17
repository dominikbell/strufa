#include "parameters/parameters_advection.hpp"
#include "vvariables/variables_advection.hpp"
#include "initial/initial.hpp"

Variables_Advection_1D1V setup_advection(const Parameters_Advection_1D1V& parameters) {
  Variables_Advection_1D1V variables {parameters.N_markers, parameters.seed};
  initialize_particles(variables.particles, parameters.initial);
  return variables;
}