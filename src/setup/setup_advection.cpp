#include "parameters/parameters_advection.hpp"
#include "vvariables/variables_advection.hpp"

Variables_Advection_1D1V setup_advection(const Parameters_Advection_1D1V& parameters) {
  return Variables_Advection_1D1V(parameters.N_markers);
}