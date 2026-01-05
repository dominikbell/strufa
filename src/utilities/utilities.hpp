#pragma once

#include <cassert>
#include <iostream>
#include <string>

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
    template <typename> class Outer,
    template <typename> class Inner,
    typename Dim
>
struct GetInnerType<Outer<Inner<Dim>>> {
    using type = Dim;
};

template <typename T>
using GetInnerType_t = typename GetInnerType<T>::type;

// =====================================================================================
// Templating trickery to get the first and second type of a templated class
template <typename T>
struct GetFirstAndSecondType;

template <
    template <typename, typename> class Outer,
    typename First,
    typename Second
>
struct GetFirstAndSecondType<Outer<First, Second>> {
  using first = First;
  using second = Second;
};

template <typename T>
using GetFirstType_t = typename GetFirstAndSecondType<T>::first;

template <typename T>
using GetSecondType_t = typename GetFirstAndSecondType<T>::second;

// =====================================================================================
