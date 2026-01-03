# add_subdirectory(functions)
# add_subdirectory(initial_condition)
add_subdirectory(initialization)
add_subdirectory(io)
add_subdirectory(fields)
add_subdirectory(models)
add_subdirectory(parameters)
add_subdirectory(particles)
add_subdirectory(utilities)
add_subdirectory(vvariables)

# Create the main executable
add_executable(strufa main.cpp)

# Link the private libraries
# target_link_libraries(strufa PRIVATE functions)
# target_link_libraries(strufa PRIVATE initial_condition)
target_link_libraries(strufa PRIVATE initialization)
target_link_libraries(strufa PRIVATE fields)
target_link_libraries(strufa PRIVATE models)
# target_link_libraries(strufa PRIVATE models_1d)
target_link_libraries(strufa PRIVATE model_parameters)
target_link_libraries(strufa PRIVATE parameters)
target_link_libraries(strufa PRIVATE parser)
target_link_libraries(strufa PRIVATE particles)
# target_link_libraries(strufa PRIVATE scenario)
target_link_libraries(strufa PRIVATE vvariables)

# Make the folders' headers available
# target_include_directories(strufa PRIVATE functions)

# Then finally add the directory to the target
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/include)