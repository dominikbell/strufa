#pragma once

#include <nlohmann/json.hpp>
#include <string>
#include <variant>

#include "initial/space_initial.hpp"
#include "initial/velocity_initial.hpp"
#include "models/base/models.hpp"
#include "utilities/dimensions.hpp"

using json = nlohmann::json;

struct BaseParameters {
  const Model model;
  const int space_dimensions;
  const int velocity_dimensions;

  BaseParameters(
      Model model_i,
      int space_dimensions_i,
      int velocity_dimensions_i = 0)
      : model {model_i},
        space_dimensions {space_dimensions_i},
        velocity_dimensions {velocity_dimensions_i} {}
};

struct Parameters1D {
  const double domain_length;

  Parameters1D(
      double domain_length_i)
      : domain_length {domain_length_i} {};

    Parameters1D(const Parameters1D& other) = default;
    Parameters1D(Parameters1D&& other) noexcept = default;
};

struct TimeParameters {
  const double dt;
  const double T_end;

  TimeParameters(double dt_i, double T_end_i) : dt {dt_i}, T_end {T_end_i} {}
};

using Parameters = std::variant<Parameters1D>;

BaseParameters get_base_parameters(const json& data);
Parameters1D get_parameters_dimensionful(const Dimensions1D& dimensions, const json& data);
Parameters get_parameters(const SpaceDimensions& space_dimension, const json& data);
TimeParameters get_time_parameters(const json& data);
