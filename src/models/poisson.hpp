#pragma once

#include "models.hpp"
#include "parameters/parameters.hpp"
#include "vvariables/model_variables.hpp"
#include "vvariables/vvariables.hpp"

template <typename TDimensions>
void run(
    Variables<Poisson, TDimensions>& variables,
    const Parameters<Poisson, TDimensions>& parameters) {}
