# Create a library from the advection sources
add_library(
    runner
    STATIC
    run_advection.cpp
)

# Include directory for this library
target_include_directories(
    runner
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/src
)