#pragma once

#include <variant>

#include "models/base/models.hpp"
#include "particles/particles.hpp"
#include "utilities/dimensions.hpp"
#include "vvariables/model_variables.hpp"

template <typename Dimensions>
struct Variables<Advection, Dimensions> {
  Particles<Dimensions, FullF> particles;

  auto as_tuple() {
    return std::tie(particles);
  }
};

using AdvectionVariablesVariant = std::variant<
    Variables<Advection, D1V1>,
    Variables<Advection, D1V2>,
    Variables<Advection, D1V3>,
    Variables<Advection, D2V2>,
    Variables<Advection, D2V3>,
    Variables<Advection, D3V3> >;
