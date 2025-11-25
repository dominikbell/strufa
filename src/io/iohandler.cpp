#include <iostream>
#include <fstream>

void readFile()
{
  // Path must be relative to main.cpp
  std::ifstream inputFile("../example.txt");

  if (inputFile.is_open()) {
    std::string line;

    std::cout << "Opened file, now reading its content ...\n\n";

    while (std::getline(inputFile, line)) {
      std::cout << line << '\n';
    }
    std::cout << '\n';

    inputFile.close();
    std::cout << "Finished reading the file and closed it.\n";
  } else {
    std::cerr << "Unable to open the file!";
  }
}