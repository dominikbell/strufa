# Create a library from the advection sources
add_library(
    models
    STATIC
    advection.cpp
)

# Include directory for this library
target_include_directories(
    models
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/src
)