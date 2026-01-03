#pragma once

#include <variant>

#include "functions/maxwellian.hpp"

template <typename Type>
struct VelocityInitialCondition;

using VelocityInitialVariant = std::variant<MaxwellianVariant>;
