# Recursion


- Writing recursive functions requires a somewhat different way of thinking than writing loops.  For some of you, it will feel a bit like magic at first, but with practice it will become more understandable.
- A recursive function can have multiple base cases and/or multiple recursive cases.
- Do not put loops in your recursive functions.  It is too easy for someone new to recursion to fool themselves into thinking they have a working recursive function, which in reality is not actually recursive.
- Sometimes recursive functions use helper functions that set up the initial parameters for the recursive function.  See the examples below.
- In section 14.9 the textbook says "There are, however, some recursive algorithms (like the one used to compute the Fibonacci sequence) that in the course of solving a problem recompute solutions to the same subproblems over and over again.  such algorithms tend to be extremely inefficient and should always be avoided in favor of iteration."  That is not quite correct.  It is true that you should avoid inefficient recursive solutions (just as it's true that you should avoid inefficient iterative solutions), however, just because the most obvious recursive solution is inefficient does not mean that no efficient recursive solution exists.  See example 2 below.


***

```c++
void draw_rectangle_iter(int num) {
  for( ;num > 0; num--) {
    cout << "**********" << endl;
    cout << "*   " << num << "    *" << endl;
    cout << "**********" << endl;
  }
}

void draw_rectangle_rec(int num) {
  if(num > 0) {
    draw_rectangle_rec(--num);
    cout << "**********" << endl;
    cout << "*   " << num << "    *" << endl;
    cout << "**********" << endl;
  }
}
```

```
Iteration:
**********
*   2    *
**********
**********
*   1    *
**********
```
```
Recursive:
**********
*   0    *
**********
**********
*   1    *
**********
**********
*   2    *
**********

```

***
## factorial Recursively
```
factorial(4) = 4 * factorial(3)
             = 4 * (3 * factorial(2))
             = 4 * (3 * (2 * factorial(1)))
             = 4 * (3 * (2 * 1 * factorial(0))) 
                                  ------------ basic case =>
             = 4 * 3 * 2 * 1 * 1
```
```c++
int factorial(int num) {
  if(num == 1) {
    return 1;
  }
  cout << "Current num: " << num << endl;
  return num * factorial(num - 1);
}
```

***

## Quick Sort (Used Divide and Conquer Algorithm)

[Quick Sort](https://www.youtube.com/watch?v=COk73cpQbFQ)

```c++
void quickSort(int arr[], int start, int end);
int partition(int arr[], int start, int end);
void swap(int arr[], int i, int j);


void quickSort(int arr[], int start, int end) {
  if(start >= end) return;
  int partitionIndex = partition(arr, start, end);
  cout << "PartitionIndex:" << partitionIndex << endl;
  quickSort(arr, start, partitionIndex - 1);
  quickSort(arr, partitionIndex + 1, end);
}


int partition(int arr[], int start, int end) {
  int partitionIndex = start; // 界線
  int pivot = arr[end];
  for(int i = start; i < end; i++) {
    if(arr[i] <= pivot) {
      swap(arr, i, partitionIndex);
      partitionIndex++;
    }
  }
  swap(arr, end, partitionIndex);
  return partitionIndex;
}


void swap(int arr[], int i, int j) {
  int temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
}
```
***

## Merge Sort
[Merge Sort](https://www.youtube.com/watch?v=TzeBrDU-JaY)

```c++
void mergeSort(int arr[], int size);

void merge(int arrA[], int arrL[], int leftCount, int arrR[], int rightCount);

void merge(int arrA[], int arrL[], int leftCount, int arrR[], int rightCount) {
  int i = 0, j = 0, k = 0;
  // i - to mark the index of left subarray(L)
  // j - to mark the index of right subarray(R)
  // k - to mark the index of merged array(A)

  while(i < leftCount && j < rightCount) {
    if(arrL[i] < arrR[j]) {
      arrA[k++] =arrL[i++];
    } else {
      arrA[k++] = arrR[j++];
    }
  }
  while( i < leftCount) arrA[k++] = arrL[i++];
  while( j < rightCount) arrA[k++] = arrR[j++];
}

void mergeSort(int arr[], int size) {
  if(size == 1) return;
  int mid = size / 2;

  int* L = new int[mid];
  int* R = new int[size - mid];

  int k = 0;

  for(int i = 0; k < mid; i++) L[i] = arr[k++];
  for(int i = 0; k < size; i++) R[i] = arr[k++];

  mergeSort(L, mid);
  mergeSort(R, size - mid);

  merge(arr, L, mid, R, size - mid);
  delete[](L);
  delete[](R);
}

int main() {
  int arr[] = {1,5,3,10,9,7};
  mergeSort(arr, 5);

  for(int i = 0; i < 5; i++)
    cout << arr[i] << endl;
}

```

***

## Factorial Function

```c++
int factorial(int num) {
  if(num == 0) {
      return 1;
  } else {
      return num * factorial(num - 1); 
  }
}
```

## Recursive gcd Function

```c++
// gcd(x, y) = gcd(y, x%y) -> if x % t == 0, y us gcd
int gcd(int x, int y) {
    if(x % y == 0) {
      return y;
    }
    return gcd(y, x % y);
}
```

## Fibonacci

```c++
int fib(int num) {
  if(num == 0) return 0;
  if(num == 1) return 1;

  return fib(num - 1) + fib(num - 2);
}
```

## Binary Search

```c++
int binarySearch_rec(int arr[], int start, int end, int target) {
  if(start > end) {
    return -1;
  }

  int mid = start + (end - start) / 2;

  if(arr[mid] == target) {
    return mid;
  } else if(arr[mid] > target) {
    return binarySearch_rec(arr, start, mid -1, target);
  } else {
    return binarySearch_rec(arr, mid + 1, end, target);
  }
}
```

## Quick Sorty in Recursive way

- 做 partition : 先選定最後一個數字當作 pivot，使用一個for loop當作scan，從start到end-1個數，另外取start作為pibotBundary，當arr[scan] < pivotValue 時，swap sacn 和 pivotBoundry內的數字，並且將pivotBoundry ++，掃完整個array後，將原先最後一個pivot和當前的pivotBoundry數字swap，最後Return povitBoundry的位置（這個數字已經排序到所需的位置）

- 有了pivotBoundry的位置後，我們再將此數組丟入quickSort中，先處理pivotBoundry以前的數字，當start < end 的時候，再次處理partition，然後丟入quickSrot中，接著我們處理quickSort pivotBoundry以的位置。（why not start = end: 因為當start==end的時候，代表只有傳入一個正確的pivotBoundry position)


```
1 3 2 6 5 4
          *
1 3 2 4 5 6
      *
1 3 2   4   5 6
    *         *
1  2  3  4  5 6
   *
1 2 3 4 5 6 
```


```c++
int partition(int arr[], int start, int end);
void quickSort(int arr[], int start, int end);
void swap(int arr[], int j, int k);

int partition(int arr[], int start, int end){
  int pivotValue = arr[end];
  int pivotB = start; // B for Boundry

  for(int pos = start; pos < end; pos ++) {
    if(arr[pos] < pivotValue) {
      swap(arr, pos, pivotB);
      pivotB++;
    }
  }

  swap(arr, end, pivotB);
  return pivotB;
}


void quickSort(int arr[], int start, int end) {
  if(start < end) {
    int p = partition(arr, start, end);
    quickSort(arr, start, p-1);
    quickSort(arr, p+1, end);
  }
}

void swap(int arr[], int i, int j) {
  int temp = arr[j];
  arr[j] = arr[i];
  arr[i] = temp;
}
```