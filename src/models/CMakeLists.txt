add_subdirectory(base)
add_subdirectory(1D)
# add_subdirectory(2D)
# add_subdirectory(3D)

# # Create a library from the advection sources
# add_library(
#     models_1d
#     STATIC
#     1D/advection/advection.cpp
# )

# # Include directory for this library
# target_include_directories(
#     models_1d
#     PUBLIC
#     ${CMAKE_CURRENT_SOURCE_DIR}
#     ${CMAKE_SOURCE_DIR}/src
# )