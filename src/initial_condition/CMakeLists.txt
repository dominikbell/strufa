add_subdirectory(scenario)

# Create a library from the initial sources
add_library(
    initial_condition
    STATIC
    initial_condition.cpp
    space_initial_condition.cpp
    velocity_initial_condition.cpp
)

# Include directory for this library
target_include_directories(
    initial_condition
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/src
)