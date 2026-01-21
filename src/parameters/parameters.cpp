#include "parameters.hpp"

#include <type_traits>
#include <variant>

#include "utilities/dimensions.hpp"
// #include "parameters/advection/get_parameters_advection.hpp"

ParametersVariant get_parameters(
    const ModelVariant& model_variant,
    const DimensionsVariant& dimensions_variant,
    const json& data) {
  std::visit(
      [&](const auto& model) -> ParametersVariant {
        using Model = std::decay_t<decltype(model)>;
        return get_parameters<Model>(dimensions_variant, data);
      },
      model_variant);
  exit_with_failure("Something went severly wrong!");
}
