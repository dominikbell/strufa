add_subdirectory(advection)
add_subdirectory(poisson)

# Create a library from the advection sources
add_library(
    vvariables
    STATIC
    vvariables.cpp
)

# Include directory for this library
target_include_directories(
    vvariables
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/src
)
