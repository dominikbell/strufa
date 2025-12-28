add_subdirectory(advection)

# Create a library from the advection sources
add_library(
    parameters
    STATIC
    parameters.cpp
    advection/parameters_advection.cpp
)

# Include directory for this library
target_include_directories(
    parameters
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/src
)