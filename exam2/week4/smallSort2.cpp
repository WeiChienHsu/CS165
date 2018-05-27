#include <iostream>

void smallSort2(int *a, int *b, int *c) {
  if(*a > *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
  }

  if(*a > *c) {
    int temp = *a;
    *a = *c;
    *c = temp;
  }

  if(*b > *c) {
    int temp = *b;
    *b = *c;
    *c = temp;
  }
}

int main() {
  int first = 14;
  int second = -90;
  int third = 2;
  smallSort2(&first, &second, &third);
  std::cout << first << ", " << second << ", " << third << std::endl;
  return 0;
}