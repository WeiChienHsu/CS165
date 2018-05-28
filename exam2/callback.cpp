#include <iostream>
void callback() {
  std::cout << "Call Back Function we called! " << std::endl;
}

void B(void (*ptr)()) {
  ptr(); // Pass a function into the funciton by using pointer ponints to funciton
}

int main() {
  B(callback);
  return 0;
}