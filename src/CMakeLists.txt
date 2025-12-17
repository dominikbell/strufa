add_subdirectory(functions)
add_subdirectory(initial)
add_subdirectory(io)
add_subdirectory(models)
add_subdirectory(parameters)
add_subdirectory(particles)
add_subdirectory(run)
add_subdirectory(setup)
add_subdirectory(vvariables)

# Create the main executable
add_executable(strufa main.cpp)

# Link the private libraries
target_link_libraries(strufa PRIVATE advection_1d)
target_link_libraries(strufa PRIVATE functions)
target_link_libraries(strufa PRIVATE initial)
target_link_libraries(strufa PRIVATE parameters)
target_link_libraries(strufa PRIVATE parser)
target_link_libraries(strufa PRIVATE runner)
target_link_libraries(strufa PRIVATE setup)
target_link_libraries(strufa PRIVATE vvariables)

# Make the folders' headers available
# target_include_directories(strufa PRIVATE functions)

# Then finally add the directory to the target
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/include)