# Create a library from the advection sources
add_library(
    functions
    STATIC
    maxwellian.cpp
    trigonometric.cpp
)

# Include directory for this library
target_include_directories(
    functions
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/src
)