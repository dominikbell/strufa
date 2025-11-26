#include<iostream>

#include "io/iohandler.hpp"

int main(int argc, char* argv[])
{
  if (argc > 1) {
    std::cout << "Program was called with parameter " << argv[1] << '\n';

    // need to use std::strlen because sizeof gives size of pointer
    std::string filename { static_cast<std::string>(argv[1]) };
    const int filename_length { static_cast<int>(filename.length()) };
    readParameterFile(filename, filename_length);
  } else {
    std::cout << "Program was called without additional parameters.\n";
  }

  return 0;
}