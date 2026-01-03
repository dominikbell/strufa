#include "initialize_variables.hpp"

#include <iostream>
#include <type_traits>

#include "particles/particles.hpp"

void initialize_variables(VariablesVariant& variables, const json& data) {
  // Visit all the models
  std::visit(
      [&](auto& model_vars_variant) {
        // Visit all the dimensions of one model
        std::visit(
            [&](auto& vars_variant) {
              // Get the tuple of variables
              std::apply(
                  [&](auto&&... variables_tuple) {
                    // Have to expand the pack tuple, some magic, can be simplified in C++20 with std::tuple_for_each
                    ([&](auto& single_variable) {
                      using var_type = std::decay_t<decltype(single_variable)>;

                      if constexpr (is_particles_v<var_type>) {
                        std::cout << "The variable has name '" << single_variable.name << "'.\n";
                      }
                      // (initialize(single_variable), ...);
                    }(variables_tuple),
                     ...);
                  },
                  vars_variant.as_tuple());
            },
            model_vars_variant);
      },
      variables);
}

// InitialConditionVariant initial_condition {get_initial_condition(pair_dimensions, data)};