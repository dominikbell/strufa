#include "run.hpp"

#include "models/advection.hpp"
#include "models/poisson.hpp"
#include "utilities/utilities.hpp"

void run(
    VariablesVariant& variables_variant,
    const ParametersVariant& parameters_variant) {
  // Visit all the models
  std::visit([&](auto& model_vars_variant, const auto& model_params_variant) {
    // Visit all the dimensions of one model
    std::visit([&](auto& variables, const auto& parameters) {
      using VariableType = std::decay_t<decltype(variables)>;
      using ParameterType = std::decay_t<decltype(parameters)>;
      using Dimensions = GetSecondType_t<VariableType>;

      // Make sure the compiler knows that parameters and variables are of the same dimensions type
      if constexpr (MatchingDimensions<VariableType, ParameterType>) {
        run(variables, parameters);
      }
    },
               model_vars_variant, model_params_variant);
  },
             variables_variant, parameters_variant);
}
