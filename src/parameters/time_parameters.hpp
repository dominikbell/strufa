#pragma once

#include <nlohmann/json.hpp>

using json = nlohmann::json;

struct TimeParameters {
  const double dt;
  const double T_end;
};

TimeParameters get_time_parameters(const json& data);
