#include "vvariables.hpp"

#include <type_traits>
#include <variant>

#include "advection/get_variables_advection.hpp"
#include "parameters/parameters.hpp"
#include "poisson/get_variables_poisson.hpp"
#include "utilities/utilities.hpp"

VariablesVariant get_variables(
    const ParametersVariant& parameters_variant,
    const Input& input) {
  // Visit all the models
  return std::visit([&](const auto& model_parameters) -> VariablesVariant {
    // Visit all the variants of a model
    return std::visit([&](const auto& parameters) -> VariablesVariant {
      using ParametersType = std::decay_t<decltype(parameters)>;
      using Dimensions = GetSecondType_t<ParametersType>;
      return get_variables<Dimensions>(parameters, input);
    },
                      model_parameters);
  },
                    parameters_variant);
}
