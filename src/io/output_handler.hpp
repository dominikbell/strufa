#pragma once

#include <ctime>
#include <chrono>
#include <string>
#include <fstream>
#include <iostream>

struct MetaData {
  const std::string file_name;
  const int n_mpi_ranks;
  const int n_omp_threads;
  std::time_t start_time;
  std::time_t end_time {0};

  MetaData(
      const std::string& file_name_i,
      const int n_mpi_ranks_i,
      const int n_omp_threads_i) : file_name(file_name_i),
                                   n_mpi_ranks(n_mpi_ranks_i),
                                   n_omp_threads(n_omp_threads_i) {
    // Get current time and convert it to ctime
    std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
    this->start_time = std::chrono::system_clock::to_time_t(now);
  }

  void write_meta() const {
    // Get current time and convert it to ctime
    std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
    std::time_t currentTime = std::chrono::system_clock::to_time_t(now);

    std::ofstream MetaFile(this->file_name, std::ios::app);

    if (MetaFile.is_open()) {
      MetaFile << "Run started at:\t\t" << std::ctime(&(this->start_time));
      MetaFile << "Run ended at:\t\t" << std::ctime(&currentTime) << '\n';
      MetaFile << "MPI processes:\t\t" << this->n_mpi_ranks << '\n';
      MetaFile << "OMP threads:\t\t" << this->n_omp_threads << '\n';
      MetaFile.close();
    } else {
      std::cerr << "Error opening file!\n";
    }
  }
};
