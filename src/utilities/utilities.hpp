#pragma once

#include <cassert>
#include <iostream>
#include <string>
#include <type_traits>

[[noreturn]]
void exit_with_failure(const std::string& message);

template <typename T>
[[noreturn]]
inline void exit_with_failure(const std::string& what, const T& wrong_input) {
  std::cerr << "Invalid " << what << " '" << wrong_input << "' detected! Aborting..\n";
  std::exit(EXIT_FAILURE);
}

std::string make_initialization_key(std::string name);

// =====================================================================================
// Templating trickery to get the inner type of a templated class
template <typename T>
struct GetInnerType;

template <
    template <typename...> class TOuter,
    typename TInner>
struct GetInnerType<TOuter<TInner>> {
  using Inner = TInner;
};

template <typename T>
using GetInnerType_t = typename GetInnerType<typename std::remove_cvref_t<T>>::Inner;

// Templating trickery to get the first and second type of a templated class
template <typename T>
struct GetFirstAndSecondType;

template <
    template <typename...> class TOuter,
    typename TFirst,
    typename TSecond>
struct GetFirstAndSecondType<TOuter<TFirst, TSecond>> {
  using First = TFirst;
  using Second = TSecond;
};

template <typename T>
using GetFirstType_t = typename GetFirstAndSecondType<typename std::remove_cvref_t<T>>::First;

template <typename T>
using GetSecondType_t = typename GetFirstAndSecondType<typename std::remove_cvref_t<T>>::Second;

// =====================================================================================
// A concept to enforce that two types are of the same type
template <typename T, typename U>
concept MatchingTypes = std::is_same_v<T, U>;

// A concept to enforce that two types are of the same dimensions (must be second template typename)
template <typename T, typename U>
concept MatchingDimensions = std::is_same_v<GetSecondType_t<T>, GetSecondType_t<U>>;
