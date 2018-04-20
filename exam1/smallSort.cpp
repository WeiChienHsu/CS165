#include <iostream>

void smallSort(int &first, int &second, int &third);
void swap(int &large, int &samll);

int main() {
  int first, second, third;
  std::cout << "Please enter three numbers: " << std::endl;
  std::cin >> first >> second >> third;

  smallSort(first, second, third);
  std::cout << first << ", " << second << ", " << third << std::endl;
  return 0;
}

void smallSort(int &first, int &second, int &third) {
  if(first > second) {
    swap(first, second);
  }

  if(first > third) {
    swap(first, third);
  }

  if(second > third) {
    swap(second, third);
  }
}

void swap(int &large, int &small) {
  int temp = large;
  large = small;
  small = temp;
}