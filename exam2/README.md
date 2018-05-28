## The core topics you should focus on include:

#### Chapter 8 Array
- arrays
- accessing and modifying arrays
- passing arrays as arguments to functions
- multidimensional arrays

```c++
void displayArray(int arr[], int size) {
  for(int i = 0; i < size; i++) {
    std::cout << arr[i] << std::endl;
  }
}

void displayPassByReference(int *arr, int size) {
  for(int i = 0; i < size; i++) {
    std::cout << arr[i] << std::endl;
  }
}
```
```c++
 /****
  * Multidimensional Array
  ****/ 
  const int ROW = 2;
  const int COL = 4;
  int arr[ROW][COL] = {{1, 2, 3, 4}, {4, 8, 12, 16 }};
  int (*ptr)[4] = arr;

  for(int i = 0; i < ROW; i++) {
    for(int j = 0; j < COL; j++) {
      std::cout << * (ptr[i] + j) << std::endl;
    }
  }
```


***

#### Chapter 12 C-strings (沒上過)
- C-style strings

***

#### Chapter 10 Pointer
- pointer variables
- the address operator (&)
- using pointers
- dynamic memory allocation

```c++
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
```

***

#### Chpater 9 Searching Sorting and Alogrithm Analysis
- searching and sorting
- time complexity and big-O notation
```c++
void bubbleSort(int *arr, int size) {
  for(int i = 0; i < size; i++) {
    for(int j = 0; j < size - 1; j++) {
      if(arr[j] > arr[j+1]) {
        int temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }
}
```
```c++
void selectionSort(int *arr, int size) {
  int minIndex = 0;
  int minValue = arr[0];
  for(int i = 0; i < size - 1; i++) {
    minIndex = i;
    minValue = arr[i];
    for(int j = i + 1; j < size; j++) {
      if(minValue > arr[j]) {
        minIndex = j;
      }
    }
    if(minIndex != i) {
      int temp = arr[i];
      arr[i] = arr[minIndex];
      arr[minIndex] = temp;
    }
  }
}
```



***

#### Chpater 14 Recursion
- recursion
```c++
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
```c++
bool isDecreasing(int *arr, int size) {
  if(size == 1) return true;

  if(arr[size - 1] < arr[size - 2]) {
    return true && isDecreasing(arr, size - 1);
  } else {
    return false;
  }
}
```

***

#### Chapter 11 OOP + Overriding
- The this pointer and constant member functions
- static members
- friend functions
- copy constructors
- operator overloading
- conversion operators
- convert constructors
- aggregation and composition
- inheritance
- protected (an access modifier)
- overriding base class functions

```c++
class NumberArray {
  private:
    int *ptr;
    int arraySize;
  public:
    NumberArray(int size, int value) {
      this->arraySize = size;
      this->ptr = new int[this->arraySize];
      setValue(value);
    }

    NumberArray(const NumberArray &obj) {
      this->arraySize = obj.arraySize;
      this->ptr = new int[this->arraySize];
      for(int i = 0; i < this->arraySize; i++){
        ptr[i] = obj.ptr[i];
      }
    }

    void printValue() {
       for(int i = 0; i < this->arraySize; i++) {
        std::cout << ptr[i] << std::endl;
      }     
    }

    void setValue(int value) {
      for(int i = 0; i < this->arraySize; i++) {
        ptr[i] = value;
      }
    }
};
```
***

#### Chpater 15 Polymorphism and Virtual functions
- polymorphism and virtual functions
- abstract base classes and pure virtual functions

***

#### Chapter 16 Exception and Template Function (STL)
- exception handling
- template functions and classes

***

#### Chpater 17 List
- linked lists

***

#### Chapter 18 Stack and Queue
- stacks and queues
 

***

## Some things that will not be on the exam are:
- parallel arrays
- pointer arithmetic
- typedef
- jagged arrays
- vectors
- sections 11.7 and 11.8
- the Standard Template Library

***