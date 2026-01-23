add_library(models INTERFACE)
target_include_directories(models INTERFACE ${CMAKE_SOURCE_DIR}/src)
target_link_libraries(models INTERFACE OpenMP::OpenMP_CXX)

# Create a library from the sources
add_library(
    run
    STATIC
    run.cpp
)

# Include directory for this library
target_include_directories(
    run
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/src
)

target_link_libraries(run PRIVATE models)
