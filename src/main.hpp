#pragma once
// Collects global properties that need to be seen by the whole program

#include <cstddef>

// The maximum available spline degree, used for allocating arrays on the stack
constexpr std::size_t MAX_DEGREE = 10;
