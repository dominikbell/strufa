#include "variables_advection.hpp"

#include <variant>

#include "advection/from_parameters_advection.hpp"
#include "parameters/advection/parameters_advection.hpp"
#include "particles/particles.hpp"

AdvectionVariablesType get_variables(const AdvectionParametersType& parameters) {
  return std::visit(
      [](auto const& arg) -> AdvectionVariablesType {
        return get_variables_dimensionful(arg);
      },
      parameters);
}

void initialize_variables(const VariablesAdvection1D1V& variables) {
  // std::pair<Space_Initial_Type, Velocity_Initial_Type> pair_initial {get_space_velocity_initial(input)};
  // Space_Initial_Type space_initial = pair.first;
  // Velocity_Initial_Type velocity_initial = pair.second;

  // What we want to do
  // initialize_positions(variables,)
  // initialize_velocities(variables,)
  // initialize_weights(variables,)
}
