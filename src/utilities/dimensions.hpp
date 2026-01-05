#pragma once

#include <utility>
#include <variant>

template <int SpaceDimensions, int VelocityDimensions = 0>
struct Dimensions {
  static constexpr int space_dimensions = SpaceDimensions;
  static constexpr int velocity_dimensions = VelocityDimensions;
};

using D1 = Dimensions<1>;
using D2 = Dimensions<2>;
using D3 = Dimensions<3>;
using V1 = Dimensions<0, 1>;
using V2 = Dimensions<0, 2>;
using V3 = Dimensions<0, 3>;
using D1V1 = Dimensions<1, 1>;
using D1V2 = Dimensions<1, 2>;
using D1V3 = Dimensions<1, 3>;
using D2V2 = Dimensions<2, 2>;
using D2V3 = Dimensions<2, 3>;
using D3V3 = Dimensions<3, 3>;

using SpaceDimensionsVariant = std::variant<D1, D2, D3>;
using VelocityDimensionsVariant = std::variant<V1, V2, V3>;
using PhaseSpaceDimensionsVariant = std::variant<D1V1, D1V2, D1V3, D2V2, D2V3, D3V3>;

SpaceDimensionsVariant get_space_dimensions(int space_dimensions);

VelocityDimensionsVariant get_velocity_dimensions(int velocity_dimensions);

PhaseSpaceDimensionsVariant get_phase_space_dimensions(std::pair<int, int> pair_dimensions);
