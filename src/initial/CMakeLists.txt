add_subdirectory(scenarios)

# Create a library from the initial sources
add_library(
    initial
    STATIC
    particle_initialization.cpp
    field_initialization.cpp
    space_initial.cpp
    velocity_initial.cpp
)

# Include directory for this library
target_include_directories(
    initial
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/src
)