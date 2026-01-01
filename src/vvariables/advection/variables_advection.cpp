#include "variables_advection.hpp"

AdvectionVariablesVariant get_variables_advection(
    std::pair<int, int> pair_dimensions,
    const AdvectionParametersVariant& parameters) {
  PhaseSpaceDimensionsVariant phase_space_dims {get_phase_space_dimensions(pair_dimensions)};

  return std::visit(
      [&](auto const& arg) -> AdvectionVariablesVariant {
        using Dim = std::decay_t<decltype(arg)>;
        return get_variables_advection<Dim>(parameters);
      },
      phase_space_dims);
}
