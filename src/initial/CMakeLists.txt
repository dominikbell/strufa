# Create a library from the initial sources
add_library(
    initial
    STATIC
    initial.cpp
)

# Include directory for this library
target_include_directories(
    initial
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/src
)