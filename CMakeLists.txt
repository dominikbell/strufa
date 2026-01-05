cmake_minimum_required(VERSION 3.25)

# project name
project(strufa)

# Use C++17 (adjust if needed)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add include folder here so it is seen by everything below
include_directories(${CMAKE_SOURCE_DIR}/include)

# Add src folder in which the executable is defined
add_subdirectory(src)

# To improve Zed highlighting
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
