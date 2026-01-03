#include "utilities.hpp"

[[noreturn]]
void exit_with_failure(const std::string& message) {
  std::cerr << message << '\n';
  std::exit(EXIT_FAILURE);
}

std::string make_initialization_key(std::string name) {
  return name + "_initialization";
}
