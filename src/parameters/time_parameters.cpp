#include "time_parameters.hpp"

#include "io/input_parser.hpp"

TimeParameters get_time_parameters(const json& data) {
  assert_top_level_keyword(data, "time");
  assert_second_level_keyword(data, "time", "dt");
  assert_second_level_keyword(data, "time", "T_end");

  double dt {data["time"]["dt"]};
  double T_end {data["time"]["T_end"]};

  TimeParameters time_parameters {dt, T_end};
  return time_parameters;
}
