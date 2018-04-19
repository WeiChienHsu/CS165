#include <iostream>
#include <string>

int main() {
  std::string str_obj;
  str_obj = "Hello World!";

  std::cout << "Contents: " << str_obj << std::endl;
  std::cout << "Length: " << str_obj.length() << std::endl;
  std::cout << "Third Chatactor: " << str_obj.at(2) << std::endl;
  return 0;
}