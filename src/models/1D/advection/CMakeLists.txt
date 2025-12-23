# Create a library from the parser sources
add_library(
    models_1d
    STATIC
    advection_1D.cpp
)

# Include directory for this library
target_include_directories(
    models_1d
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/src
)