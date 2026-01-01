#include "vvariables.hpp"

#include "parameters/parameters.hpp"

VariablesVariant get_variables(
    std::pair<int, int> pair_dimensions,
    const ParametersVariant& parameters) {
  return std::visit(
      [&](auto const& arg) -> VariablesVariant {
        using arg_type = std::decay_t<decltype(arg)>;

        if constexpr (std::is_same_v<arg_type, AdvectionParametersVariant>) {
          return get_variables_advection(pair_dimensions, arg);
        } else if constexpr (std::is_same_v<arg_type, PoissonParametersVariant>) {
          return get_variables_poisson(pair_dimensions, arg);
        }
      },
      parameters);
}
