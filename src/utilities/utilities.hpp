#pragma once

#include <cassert>
#include <iostream>

inline void exit_with_failure(const std::string& message) {
  std::cerr << message << '\n';
  std::exit(EXIT_FAILURE);
}

template <typename T>
inline void exit_with_failure(const std::string& what, const T& wrong_input) {
  std::cerr << "Invalid " << what << " '" << wrong_input << "' detected! Aborting..\n";
  std::exit(EXIT_FAILURE);
}
