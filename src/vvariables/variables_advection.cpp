#include "variables_advection.hpp"
#include "parameters_to_variables_advection.hpp"

#include <variant>

#include "parameters/parameters_advection.hpp"
#include "particles/particles.hpp"

// Variables_Advection_1D1V get_variables_dimensionful(const Parameters_Advection_1D1V& parameters) {
//   Variables_Advection_1D1V variables {parameters};
//   return variables;
// }

// Variables_Advection_1D2V get_variables_dimensionful(const Parameters_Advection_1D2V& parameters) {
//   Variables_Advection_1D2V variables {parameters};
//   return variables;
// }

Advection_Variables_Type get_variables(const Advection_Parameters_Type& parameters) {
  return std::visit(
      [](auto arg) -> Advection_Variables_Type {
        return get_variables_dimensionful(arg);
      },
      parameters);
}

void initialize_variables(const Variables_Advection_1D1V& variables) {
  // std::pair<Space_Initial_Type, Velocity_Initial_Type> pair_initial {get_space_velocity_initial(input)};
  // Space_Initial_Type space_initial = pair.first;
  // Velocity_Initial_Type velocity_initial = pair.second;

  // What we want to do
  // initialize_positions(variables,)
  // initialize_velocities(variables,)
  // initialize_weights(variables,)
}
