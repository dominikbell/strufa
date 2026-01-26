add_library(particles INTERFACE)
target_include_directories(particles INTERFACE
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/src
)
target_link_libraries(particles INTERFACE HDF5::HDF5)
