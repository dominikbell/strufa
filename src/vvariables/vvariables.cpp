#include "vvariables.hpp"

#include <type_traits>
#include <variant>

#include "parameters/parameters.hpp"
#include "utilities/utilities.hpp"
#include "advection/get_variables_advection.hpp"
#include "poisson/get_variables_poisson.hpp"

VariablesVariant get_variables(const ParametersVariant& parameters_variant) {
  // Visit all the models
  return std::visit([&](const auto& model_parameters) -> VariablesVariant {
    // Visit all the variants of a model
    return std::visit([&](const auto& parameters) -> VariablesVariant {
      using ParametersType = std::decay_t<decltype(parameters)>;
      using Dimensions = GetSecondType_t<ParametersType>;
      return get_variables<Dimensions>(parameters);
    },
                      model_parameters);
  },
                    parameters_variant);
}
