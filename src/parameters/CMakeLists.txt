# Create a library from the advection sources
add_library(
    setup
    STATIC
    setup.cpp
)

# Include directory for this library
target_include_directories(
    setup
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)