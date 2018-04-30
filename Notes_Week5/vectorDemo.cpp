#include <iostream>
#include <vector>
#include <iomanip>


int main() {
  const int NUM_EMPS = 5;
  std::vector <int> hours;


  for(int i = 0; i < NUM_EMPS; i++) {
    hours.push_back(i);
  }

  for(int num : hours){
    std::cout << num << std::endl;
  }

  std::cout << hours.size() << std::endl;
  std::cout << hours.at(3) << std::endl;
  return 0;
}