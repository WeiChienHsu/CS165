#include <iostream>
using namespace std;

// We Could change the implement of this compare funciton to any kinds of comparasions (absoult value as well)
int compare(int a, int b) {
  if(a > b) return -1;
  else return 1;
}

void BubbleSort(int *A, int n, int (*compare)(int, int)) {
  int i, j, temp;
  for(i = 0; i < n; i++){
    for(j = 0; j < n - 1; j++) {
      if(compare(A[j], A[j+1]) > 0) {
        temp = A[j];
        A[j] = A[j+1];
        A[j+1] = temp;
      }
    }
  }
}

int main() {
  int i, A[] = {3,2,1,5,6,4};
  BubbleSort(A, 6, compare); // Pase Address of A[], size, compare callback function
  for(int i = 0; i < 6; i++) {
    cout << A[i] << endl;
  }
  return 0;
}