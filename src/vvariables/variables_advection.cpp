#include "variables_advection.hpp"

#include <variant>

#include "parameters/parameters_advection.hpp"
#include "particles/particles.hpp"

Advection_Variables_Type get_variables(const Advection_Parameters_Type& parameters) {
    return std::visit(
      [](auto arg) -> Advection_Variables_Type {
        return get_variables_dimensionful(arg);
      },
      parameters
    );
  }

Variables_Advection_1D1V get_variables_dimensionful(const Parameters_Advection_1D1V& parameters) {
  Variables_Advection_1D1V variables {parameters};
  return variables;
}

void initialize_variables(const Variables_Advection_1D1V& variables) {
  // What we want to do
  // initialize_in_space(variables,)
}
