#pragma once

#include <optional>
#include <string>

enum class Background {
  none,
  maxwellian,
};

inline Background string_to_background(const std::string& str) {
  if (str == "maxwellian") {
    return Background::maxwellian;
  } else if (str == "") {
    return Background::none;
  } else {
    return Background::none;
  }
}