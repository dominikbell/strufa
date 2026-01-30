#pragma once

#include <vector>

struct Circulant {
  std::vector<double> entries;
  std::vector<int> cols;

  void dot(const std::vector<double>& input, std::vector<double>& output) {
    size_t n_rows {input.size()};
    size_t n_entries {entries.size()};

    size_t index {};
    for (size_t i = 0; i < n_rows; ++i) {
      output[i] = 0.0;
      for (size_t j = 0; j < n_entries; ++j) {
        index = (j + i) % n_rows;
        output[i] += entries[j] * input[index];
      }
    }
  }
};

Circulant get_grad();
