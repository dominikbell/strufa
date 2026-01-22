# Create a library from the io sources
add_library(
    parser
    STATIC
    input_parser.cpp
)

# Include directory for this library
target_include_directories(
    parser
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/src
)
