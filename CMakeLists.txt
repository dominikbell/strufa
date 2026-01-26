cmake_minimum_required(VERSION 3.25)

# project name
project(strufa)

# Use C++20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Use OpenMP and MPI
find_package(OpenMP REQUIRED)
# find_package(MPI REQUIRED)
find_package(HDF5 REQUIRED)

# Add include folder here so it is seen by everything below
include_directories(${CMAKE_SOURCE_DIR}/include)

# Add src folder in which the executable is defined
add_subdirectory(src)

# Link with OpenMPI and MPI
target_link_libraries(strufa PUBLIC OpenMP::OpenMP_CXX)
# target_link_libraries(strufa PUBLIC MPI::MPI_CXX)
target_link_libraries(strufa PUBLIC HDF5::HDF5)

# To improve Zed highlighting
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
