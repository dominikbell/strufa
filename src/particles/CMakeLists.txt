# Create a library from the advection sources
add_library(
    sample
    STATIC
    sample.cpp
)

# Include directory for this library
target_include_directories(
    sample
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/src
)