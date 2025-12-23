# Create a library from the advection sources
add_library(
    scenarios
    STATIC
    scenarios.cpp
)

# Include directory for this library
target_include_directories(
    scenarios
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/src
)