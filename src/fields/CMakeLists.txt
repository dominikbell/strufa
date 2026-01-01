# Create a library from the parser sources
add_library(
    fields
    STATIC
    fields.cpp
)

# Include directory for this library
target_include_directories(
    fields
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/src
)