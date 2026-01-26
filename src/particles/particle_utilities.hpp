#pragma once

#include "particles.hpp"

// ==========================================================================
// Templated trickery to check if an object is of a particles templated class
template <typename T>
struct is_particles : std::false_type {};

template <typename TDimensions, typename TParticleType>
struct is_particles<Particles<TDimensions, TParticleType>> : std::true_type {};

template <typename T>
inline constexpr bool is_particles_v = is_particles<T>::value;
// ==========================================================================
