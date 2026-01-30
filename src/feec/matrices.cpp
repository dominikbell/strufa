#include "matrices.hpp"

#include <vector>

Circulant get_grad() {
  std::vector<double> entries {-1.0, 1.0};
  std::vector<int> cols {0, 1};
  return {entries, cols};
}
