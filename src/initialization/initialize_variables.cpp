#include "initialize_variables.hpp"

#include <iostream>
#include <string>
#include <type_traits>

#include "initial_condition/initial_condition.hpp"
// #include "initial_condition/space_initial_condition.hpp"
#include "initialize_particles.hpp"
#include "particles/particles.hpp"
#include "utilities/utilities.hpp"

void initialize_variables(
    std::pair<int, int> pair_dimensions,
    VariablesVariant& variables,
    const json& data) {
  // Visit all the models
  std::visit([&](auto& model_vars_variant) {
    // Visit all the dimensions of one model
    std::visit([&](auto& vars_variant) {
      // Get the tuple of variables
      std::apply([&](auto&&... variables_tuple) {
        // Have to expand the pack tuple, some magic, can be simplified in C++20 with std::tuple_for_each
        ([&](auto& single_variable) {
          using var_type = std::decay_t<decltype(single_variable)>;
          std::string key_name {make_initialization_key(single_variable.name)};
          std::cout << "The variable has init key '" << key_name << "'.\n";

          if constexpr (is_particles_v<var_type>) {
            std::cout << "The first two weights before initialization:\n";
            std::cout << single_variable.weights[0] << single_variable.weights[1] << '\n';
            PhaseSpaceInitialCondition initial_condition {get_phase_space_initial_condition(pair_dimensions, data[key_name])};
            initialize_particles(single_variable, initial_condition);
            std::cout << "The first two weights after initialization: " << single_variable.weights[0] << single_variable.weights[1] << '\n';
          }
          // else if constexpr (is_field_v<var_type>) {
          //   SpaceInitialVariant initial_condition {get_space_initial_condition(pair_dimensions.first, data[key_name])};
          //   initialize_field(single_variable, initial_condition);
          // }
        }(variables_tuple),
         ...);
      },
                 vars_variant.as_tuple());
    },
               model_vars_variant);
  },
             variables);
}
