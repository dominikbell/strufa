# Create a library from the advection sources
add_library(
    advection_1d
    STATIC
    advection.cpp
)

# Include directory for this library
target_include_directories(
    advection_1d
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/src/parameters
)