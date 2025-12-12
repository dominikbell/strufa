add_subdirectory(io)
# add_subdirectory(models)
# add_subdirectory(parameters)
# add_subdirectory(particles)
# add_subdirectory(run)

# Create the main executable
add_executable(strufa main.cpp)

# Link the private libraries
target_link_libraries(strufa PRIVATE parser)
# target_link_libraries(strufa PRIVATE runner)
# target_link_libraries(strufa PRIVATE setup)
# target_link_libraries(strufa PRIVATE advection_1d)

# Make the folders' headers available
# target_include_directories(strufa PRIVATE io)
# target_include_directories(strufa PRIVATE parameters)

# Then finally add the directory to the target
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/include)