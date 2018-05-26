#include <iostream>
#include <stack>
#include <cstring>

int main() {
  std::string str = "25 12 7 - 2 * /";
  char* chr = strdup(str.c_str());
  char* token = std::strtok(chr, " ");
  std::cout <<  std::atof(token) << std::endl;
  token = std::strtok(nullptr, " ");
  std::cout << token << std::endl;
  token = std::strtok(nullptr, " ");
  std::cout << token << std::endl;
  token = std::strtok(nullptr, " ");
  std::cout << token << std::endl;
  token = std::strtok(nullptr, " ");
  std::cout << token << std::endl;
  token = std::strtok(nullptr, " ");
  std::cout << token << std::endl;
  token = std::strtok(nullptr, " ");
  std::cout << token << std::endl;  
  
 
  
  return 0; 

}