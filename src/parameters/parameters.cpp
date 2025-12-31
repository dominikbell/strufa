#include "parameters.hpp"

ParametersVariant get_parameters(
    const ModelEnum& model_enum,
    std::pair<int, int> pair_dimensions,
    const json& data) {
  switch (model_enum) {
    case (ModelEnum::advection): {
      return get_parameters_advection(pair_dimensions, data);
    }
    case (ModelEnum::poisson): {
      return get_parameters_poisson(pair_dimensions, data);
    }
  }
}
