#pragma once

template <typename Variables, typename Func>
void initialize_variables(Variables& variables, Func&& func) {
  std::apply(
    [&](auto&... vars) {
      (func(vars), ...);
    },
  variables.as_tuple());
}
