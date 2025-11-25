# Create a library from the io handler sources
add_library(iohandler
    iohandler.cpp
)

# Include directory for this library
target_include_directories(iohandler PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})