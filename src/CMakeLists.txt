add_subdirectory(io)

# Create the main executable
add_executable(strufa main.cpp)

# Link the iohandler library
target_link_libraries(strufa PRIVATE iohandler)

# Make the io folder's headers available
target_include_directories(strufa PRIVATE io)