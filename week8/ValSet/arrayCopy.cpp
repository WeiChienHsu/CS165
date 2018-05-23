#include <iostream>
using namespace std;

void make(){
  int *ptr = new int[3];
  for(int i = 0; i < 3; i++) {
    ptr[i] = i;
  }

  for(int i = 0; i < 3; i++) {
    cout << "Original: " << &ptr[i] << " \n"; 
  }

  cout << " _________ " << endl;

  int *temp_ptr = new int[3*2];
  for(int i = 0; i < 3; i++) {
    temp_ptr[i] = ptr[i];
  }

  for(int i = 0; i < 6; i++) {
    cout << "temp: " << &temp_ptr[i] << " \n";
  }

  // delete[] ptr;

  ptr = temp_ptr;

  for(int i = 0; i < 6; i++) {
    cout << "New Original: " <<  &ptr[i] << " \n"; 
  }
}

int main() {
  for(int i = 0; i < 100000; i++) {
    make();
  }
  return 0;
}