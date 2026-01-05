# Create a library from the advection sources
add_library(
    utilities
    STATIC
    utilities.cpp
    dimensions.cpp
)

# Include directory for this library
target_include_directories(
    utilities
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/src
)
