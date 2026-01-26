#pragma once

#include <array>
#include <cstddef>
#include <highfive/H5File.hpp>
#include <memory>
#include <string>
#include <vector>

#include "parameters/discretization/PIC_parameters.hpp"
#include "parameters/time_parameters.hpp"

template <typename TDimensions, typename TParticleType>
struct Particles;

template <typename TDimensions>
struct Particles<TDimensions, FullF> {
  const long N_markers {0};
  const int seed {0};
  const std::string name {""};
  std::vector<double> weights;
  std::array<std::vector<double>, TDimensions::space_dimensions> positions;
  std::array<std::vector<double>, TDimensions::velocity_dimensions> velocities;
  std::unique_ptr<HighFive::File> hdf5_file;
  HighFive::DataSet dataset_weights;
  std::array<HighFive::DataSet, TDimensions::space_dimensions> datasets_positions;
  std::array<HighFive::DataSet, TDimensions::velocity_dimensions> datasets_velocities;

  Particles(
      const ParticleParameters& particle_parameters,
      const std::string& name_i)
      : N_markers {particle_parameters.N_markers},
        seed {particle_parameters.seed},
        name {name_i} {
    // Allocate memory for the particles
    weights.resize(N_markers);
    for (auto& position_vector : positions)
      position_vector.resize(N_markers);
    for (auto& velocity_vector : velocities)
      velocity_vector.resize(N_markers);
  }

  Particles(
      const ParticleParameters& particle_parameters,
      const std::string& name_i,
      const TimeParameters& time_parameters,
      const std::string& save_name_i = "")
      : N_markers {particle_parameters.N_markers},
        seed {particle_parameters.seed},
        name {name_i} {
    // Allocate memory for the particles
    weights.resize(N_markers);
    for (auto& position_vector : positions)
      position_vector.resize(N_markers);
    for (auto& velocity_vector : velocities)
      velocity_vector.resize(N_markers);

    // Assign members to save particles
    std::string save_name {save_name_i.empty() ? "particles" : save_name_i};
    hdf5_file = std::make_unique<HighFive::File>(
        save_name + ".h5",
        HighFive::File::ReadWrite | HighFive::File::Create | HighFive::File::Truncate);
    HighFive::DataSpace dataspace = HighFive::DataSpace(
        {static_cast<size_t>(time_parameters.N_timesteps),
         static_cast<size_t>(particle_parameters.N_markers)});
    dataset_weights = hdf5_file->createDataSet<double>("/weights", dataspace);
    for (int i = 0; i < TDimensions::space_dimensions; ++i) {
      datasets_positions[i] = hdf5_file->createDataSet<double>("/positions" + std::to_string(i), dataspace);
    }
    for (int i = 0; i < TDimensions::velocity_dimensions; ++i) {
      datasets_velocities[i] = hdf5_file->createDataSet<double>("/velocities" + std::to_string(i), dataspace);
    }
  }

  void save_markers(const size_t timestep) {
    if (hdf5_file) {
      dataset_weights.select(
                         {timestep, 0},
                         {1, static_cast<size_t>(N_markers)})
          .write_raw(weights.data());
    }
    for (int i = 0; i < TDimensions::space_dimensions; ++i) {
      datasets_positions[i].select(
                               {timestep, 0},
                               {1, static_cast<size_t>(N_markers)})
          .write_raw(positions[i].data());
    }
    for (int i = 0; i < TDimensions::space_dimensions; ++i) {
      datasets_velocities[i].select(
                                {timestep, 0},
                                {1, static_cast<size_t>(N_markers)})
          .write_raw(velocities[i].data());
    }
  }
};
