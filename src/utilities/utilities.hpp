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
