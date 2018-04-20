#include <iostream>
#include <string>
#include <fstream>

int main() {
  std::string FILE_NAME;

  std::cout << "Please enter your filename: " << std::endl;
  std::cin >> FILE_NAME;

  std::ifstream inputFile;
  inputFile.open(FILE_NAME);
  int value, currentValue;

  if(inputFile.fail()) {
    std::cout << "Could not access file. " << std::endl;
    inputFile.close();
  } else {
    while(inputFile >> value) {
      currentValue += value;
    }
    inputFile.close();
  }

  std::ofstream outputFile;
  outputFile.open("sum.txt");
  outputFile << currentValue;
  std::cout << "Write the sum into sum.txt" << std::endl;
  outputFile.close();

  return 0;
}