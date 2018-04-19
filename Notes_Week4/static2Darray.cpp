#include <iostream>
#define ROWS 5
#define COLS 3

int main() {
  int arr[ROWS][COLS];
  for(int i = 0; i < ROWS; i++) {
    for(int j = 0; j < COLS; j++) {
      arr[i][j] = (i + 1) * (j + 1);
      std::cout << arr[i][j] << " | ";
    }
    std::cout << "" << std::endl;
  }
  return 0;
}