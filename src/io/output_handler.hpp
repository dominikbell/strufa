#pragma once

#include <omp.h>

#include <chrono>
#include <ctime>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>

struct MetaData {
  const int n_mpi_ranks;
  const int n_omp_threads;
  std::time_t initial_time;
  const std::string file_name {"meta.txt"};
  std::time_t start_time {0};
  std::time_t end_time {0};

  MetaData(
      const int n_mpi_ranks_i) : n_mpi_ranks(n_mpi_ranks_i),
                                 n_omp_threads(omp_get_max_threads()) {
    // Get current time and convert it to ctime
    std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
    this->initial_time = std::chrono::system_clock::to_time_t(now);
  }

  void set_start_run_time() {
    std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
    this->start_time = std::chrono::system_clock::to_time_t(now);
  }

  void set_end_run_time() {
    std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
    this->end_time = std::chrono::system_clock::to_time_t(now);
  }

  void write_meta_data(const std::filesystem::path& output_path) const {
    std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
    std::time_t currentTime = std::chrono::system_clock::to_time_t(now);

    std::string file_path {output_path / this->file_name};
    std::ofstream MetaFile(file_path, std::ios::app);

    if (MetaFile.is_open()) {
      std::time_t total_time {currentTime - this->initial_time};
      MetaFile << "\n\nTotal wall clock time:\t\t" << total_time << " seconds\n";
      std::time_t runtime {this->end_time - this->start_time};
      MetaFile << "Simulation runtime:\t\t" << runtime << " seconds\n\n";
      MetaFile << "MPI processes:\t\t" << this->n_mpi_ranks << '\n';
      MetaFile << "OMP threads:\t\t" << this->n_omp_threads << '\n';
      MetaFile.close();
    } else {
      std::cerr << "Error opening file!\n";
    }
  }
};
