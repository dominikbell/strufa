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
// Templating trickery to get the first and second type of a templated class
template <typename T>
struct GetFirstAndSecondType;

template <
    template <typename...> class Outer,
    typename TFirst,
    typename TSecond>
struct GetFirstAndSecondType<Outer<TFirst, TSecond>> {
  using First = TFirst;
  using Second = TSecond;
};

template <typename T>
using GetFirstType_t = typename GetFirstAndSecondType<typename std::remove_cvref_t<T>>::First;

template <typename T>
using GetSecondType_t = typename GetFirstAndSecondType<typename std::remove_cvref_t<T>>::Second;
// =====================================================================================
