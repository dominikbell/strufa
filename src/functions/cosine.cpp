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

double call_function(const Cosine<D1>& cosine_1D, double x) {
  return cosine_1D.amplitude * cos(cosine_1D.wavenumber * x);
}

double call_function(const Cosine<D2>& cosine_2D, double x, double y) {
  return cosine_2D.amplitude * cos(cosine_2D.wavenumber_x * x + cosine_2D.wavenumber_y * y);
}
double call_function(const Cosine<D3>& cosine_3D, double x, double y, double z) {
  return cosine_3D.amplitude * cos(cosine_3D.wavenumber_x * x + cosine_3D.wavenumber_y * y + cosine_3D.wavenumber_z * z);
}
