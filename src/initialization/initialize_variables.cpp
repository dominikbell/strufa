#include "initialize_variables.hpp"

#include <string>
#include <type_traits>

#include "initial_condition/initial_condition.hpp"
// #include "initial_condition/space_initial_condition.hpp"
#include "initialize_particles.hpp"
#include "particles/particles.hpp"
#include "utilities/utilities.hpp"

void initialize_variables(
    VariablesVariant& variables_variant,
    const ParametersVariant& parameters_variant,
    const json& data) {
  // Visit all the models
  std::visit([&](auto& model_vars_variant, const auto& model_params_variant) {
    // Visit all the dimensions of one model
    std::visit([&](auto& variables, const auto& parameters) {
      using VariableType = std::decay_t<decltype(variables)>;
      using ParameterType = std::decay_t<decltype(parameters)>;
      using Dimensions = GetSecondType_t<VariableType>;

      // Make sure the compiler knows that parameters and variables are of the same dimensions type
      if constexpr (MatchingDimensions<VariableType, ParameterType>) {
        // Get the tuple of variables
        std::apply([&](auto&&... variables_tuple) {
          // Have to expand the pack tuple, some magic
          ([&](auto& single_variable) {
            using SingleVariableType = std::decay_t<decltype(single_variable)>;
            std::string key_name {make_initialization_key(single_variable.name)};

            if constexpr (is_particles_v<SingleVariableType>) {
              PhaseSpaceInitialCondition initial_condition {
                  get_phase_space_initial_condition<Dimensions>(
                      data[key_name],
                      parameters.domain_parameters)};
              initialize_particles(single_variable, initial_condition);
            }
            // else if constexpr (is_field_v<var_type>) {
            //   SpaceInitialVariant initial_condition {get_space_initial_condition(pair_dimensions.first, data[key_name])};
            //   initialize_field(single_variable, initial_condition);
            // }
          }(variables_tuple),
          ...);
        },
                  variables.as_tuple());
      } else {
        exit_with_failure("Something went severly wrong in intializing variables.");
      }
    },
               model_vars_variant, model_params_variant);
  },
             variables_variant, parameters_variant);
}
