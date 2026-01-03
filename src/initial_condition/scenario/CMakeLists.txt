# Create a library from the advection sources
add_library(
    scenario
    STATIC
    scenario.cpp
)

# Include directory for this library
target_include_directories(
    scenario
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/src
)