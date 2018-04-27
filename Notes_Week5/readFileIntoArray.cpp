#include <iostream>
#include <fstream>

int main() {
  const int NUM_EMPLOYEE = 5;
  int hours[NUM_EMPLOYEE];
  int count = 0;

  std::ifstream inputFile;
  inputFile.open("employee.txt");
  if(!inputFile) {
    std::cout << "File couldn't open" << std::endl;
  } else {
    while(count < NUM_EMPLOYEE && inputFile >> hours[count]) {
      count++;
    }
    
    inputFile.close();
  }
  for(int i = 0; i < NUM_EMPLOYEE; i++) 
    std::cout << "Employee [" << i << "]: " << hours[i] << std::endl;
  return 0;
}