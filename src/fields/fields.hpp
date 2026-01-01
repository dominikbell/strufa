#pragma once

#include "utilities/dimensions.hpp"

template <typename Dimensions>
struct Field;

template <>
struct Field<D1> {};

template <>
struct Field<D2> {};

template <>
struct Field<D3> {};
