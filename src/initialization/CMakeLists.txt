# Create a library from the initial sources
add_library(
    initialization
    STATIC
    initialize_variables.cpp
)

# Include directory for this library
target_include_directories(
    initialization
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/src
)