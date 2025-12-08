#include<optional>
#include<iostream>

#include "io/iohandler.hpp"
#include "io/parameters/parameters.hpp"

int main(int argc, char* argv[])
{
  if (argc > 1) {
    std::cout << "Program was called with parameter " << argv[1] << '\n';

    // need to use std::strlen because sizeof gives size of pointer
    std::string filename { static_cast<std::string>(argv[1]) };
    const int filename_length { static_cast<int>(filename.length()) };
    std::optional<Parameters> parameters {readParameterFile(filename, filename_length)};

    if (parameters) {
      std::cout << "Succesfully read in parameters! The models name is: " << (*parameters).model_name << '\n';
    } else {
      std::cout << "Something went wrong while reading in parameters!\n";
    }

  } else {
    std::cout << "Program was called without additional parameters.\n";
  }

  return 0;
}