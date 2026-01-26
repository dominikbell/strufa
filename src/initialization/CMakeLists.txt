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

# Needed because initialize_variables uses particle_utilities which uses hdf5
target_link_libraries(initialization PRIVATE particles)
