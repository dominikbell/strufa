#pragma once

#include <utility>
#include <variant>

#include "parameters/advection/parameters_advection.hpp"
#include "particles/particles.hpp"
#include "utilities/dimensions.hpp"
#include "vvariables/model_variables.hpp"

template <typename Dimensions>
struct Variables<Advection, Dimensions> {
  Particles<Dimensions, FullF> particles;
};

using AdvectionVariablesVariant = std::variant<
    Variables<Advection, D1V1>,
    Variables<Advection, D1V2>,
    Variables<Advection, D1V3>,
    Variables<Advection, D2V2>,
    Variables<Advection, D2V3>,
    Variables<Advection, D3V3> >;

template <typename Dimensions>
inline Variables<Advection, Dimensions>
get_variables_advection(const AdvectionParametersVariant& parameters) {
  Particles<Dimensions, FullF> particles {parameters.particle_parameters};

  return {particles};
}

AdvectionVariablesVariant get_variables_advection(std::pair<int, int> pair_dimensions, const AdvectionParametersVariant& parameters);
