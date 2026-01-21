# Discretization parameters
add_subdirectory(discretization)

# Model parameters
add_subdirectory(advection)
add_subdirectory(poisson)

# Create a library from the parameters sources
add_library(
    parameters
    STATIC
    parameters.cpp
    time_parameters.cpp
    domain_parameters.cpp
    discretization/FE_parameters.cpp
    discretization/PIC_parameters.cpp
)

# Include directory for this library
target_include_directories(
    parameters
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/src
)

# Create a library from the model parameters sources
add_library(
    model_parameters
    STATIC
    advection/get_parameters_advection.cpp
    poisson/get_parameters_poisson.cpp
)

# Include directory for this library
target_include_directories(
    model_parameters
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/src
)
