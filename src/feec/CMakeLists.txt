# Create a library from the FEEC sources
add_library(
    feec
    STATIC
    feec_utilities.cpp
)

# Include directory for this library
target_include_directories(
    feec
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/src
)
