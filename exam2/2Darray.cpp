#include <iostream>
int main() {
  const int ROW = 2;
  const int COL = 4;
  int arr[ROW][COL] = {{1, 2, 3, 4}, {4, 8, 12, 16 }};
  int (*ptr)[4] = arr;

  for(int i = 0; i < ROW; i++) {
    for(int j = 0; j < COL; j++) {
      std::cout << * (ptr[i] + j) << std::endl;
    }
  }

  return 0;
}