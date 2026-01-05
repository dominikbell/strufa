#include "cosine.hpp"

CosineVariant get_cosine(int space_dimensions, const json& data) {
  SpaceDimensionsVariant space_dims {get_space_dimensions(space_dimensions)};

  return std::visit(
      [&](auto& dim) -> CosineVariant {
        using Dim = std::decay_t<decltype(dim)>;
        return get_cosine<Dim>(data);
      },
      space_dims);
}
