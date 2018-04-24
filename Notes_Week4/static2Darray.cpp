#include <iostream>
#define ROWS 3
#define COLS 4
using namespace std;

int main() {
  int arr[ROWS][COLS]; // Static 2-D Array on Stack

  cout << "Address of arr location : " << arr << endl;
  cout << "Address of pointer location: " << &arr << endl;
  cout << "Address of next row location: " << &arr[1] << endl;
  cout << "Contnets at location: " << arr[0][0] << endl;

  for(int i = 0; i < ROWS; i++) {
    for(int j = 0; j < COLS; j++) {
      arr[i][j] = i * j;
    }
  }

    for(int i = 0; i < ROWS; i++) {
      for(int j = 0; j < COLS; j++) {
        cout << "Contnets: " << arr[i][j] << endl;
    }
  }

  int **dyarr;
  dyarr = new int* [ROWS];
  for(int i = 0; i < ROWS; i++) {
    dyarr[i] = new int[COLS];
  }

  cout << "Adress of pointer on STACK: " << &dyarr << endl;
  cout << "Address of first row location: " << dyarr[0] << endl;
  cout << "Address of Array Row: " << dyarr << endl;

  cout << "Address of next row pointer location  " << &dyarr[1] << endl;
  cout << "Address of next row :  " << dyarr[1] << endl;
  cout << "Address of next row :  " << &dyarr[1][0] << endl;
  cout << "Content of position :  " << dyarr[1][1] << endl;

  for(int i = 0; i < ROWS; i++) {
    delete [] dyarr[i];
  }
  delete [] dyarr;

  return 0;
}