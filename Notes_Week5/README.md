# Chapter 9

- Insertion sort is another sorting algorithm.  Like bubble sort and selection sort its worst-case time is O(n2),but it has a different best-case.  When the values are already nearly sorted, insertion sort runs in O(n).

- Quick sort, as its name would suggest, is one of the faster sorting algorithms.  There are other algorithms with - a better worst-case complexity - merge sort and heap sort both run in O(n lg n) worst-case, whereas for quick sort the worst-case is O(n2), the same as bubble sort!  However the average running time for quick sort is O(n lg n), and its worst case is highly improbable, so it's still a fast algorithm.

- Big-O doesn't tell you how much actual time an algorithm will take.  It tells you how quickly that time increases as the size of the input increases.

- In addition to time complexity, you can also compare the space complexity of different algorithms, which concerns how much additional space an algorithm needs to use.  There is often a tradeoff between the amount of time and the amount of space an algorithm requires.

- In coding interviews you'll be expected to be able to talk about running times.  They'll ask you to figure out the code for something on a white board and often they'll ask you about its running time and whether you can think of a way to do it that uses less time or memory.

## Binary Search
```c++
int binarySearch(int arr[], int size, int target) {
  int start = 0, end = size - 1;
  while(start + 1 < end) {
    int middle = start + (end - start) / 2;
    if(target == arr[middle]) {
        start = middle;
    } else if(target > arr[middle]) {
        start = middle;
    } else {
        end = middle;
    }
  }
```

***

## Bubble Sort
Works by comparing each element in the array with its neighbor and swapping then if they are not in the desired order.

```
Do
  Set madeAswap flag to false
  For count = 0 to the next-to-last array subscript
    If array[count] is greater than array[count +1]
      Swap the contents of array[count] and array[count+1]
      set madeAswap flag to true
    End if
  End for
While the madeAswap flag is true

```

```c++
void bubbleSort(int *arr, int size) {
  for(int curLargeIndex = size - 1; curLargeIndex >= 0; curLargeIndex--) {
    // int curLarge = arr[curLargeIndex];
    for(int j = 0; j < curLargeIndex; j++) {
      if(arr[j] > arr[j + 1]) {
        swap(arr, j, j+ 1);
      }
    }
  }
}

void bubbleSort2(int arr[], int size) {
  int count;
  bool madeAswap = false;
  do {
    for(count = 0; count < size - 1; count++) {
      madeAswap = false;
      if(arr[count] > arr[count+1]) {
        swap(arr, count, count + 1);
        madeAswap = true;
      }
    }
  } while (madeAswap);
}

void swap(int *arr, int i, int j) {
  int temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
}
```


## Selection Sort
Bubble is inefficient for large arrays because repeated data swaps are often required to place a single item in its correct position on each pass. The selection sort, like the bubble sort, places just one item in its correct position on each pass. However it usually perform fewer exchanges because it moves items immedicately to their correct position in the array.

```
For startScan = 0 to the next-to-last array subscript
  Set minIndex to startScan
  Set minValue to array[startScan]
  For index = (startScan + 1) to the last subscript in the array
    If array[index] is less than minValue
      Set minValue to array[index]
      Set minIndex to indrx
    End if
    Increment index
  End for
  ///////
  Set array[minIndex] to array[startScan]
  Set array[startScan] to minValue // Swap
End For
```  

```c++
void selectSort2(int arr[], int size) {
  int startScan, minIndex, minValue;
  for(startScan = 0; startScan < size -1; startScan++) {
    minIndex = startScan;
    minValue = arr[startScan];
    for(int currentIndex = startScan + 1; currentIndex < size; currentIndex++) {
      if(arr[currentIndex] < minValue) {
        minValue = arr[currentIndex];
        minIndex = currentIndex;
      }
    }
    swap(arr, minIndex, startScan);
  }
}


void selectSort(int arr[], int size) {
  for(int i = 0; i < size; i++) {
    // Based on current index and search the rest of array
    int minIndex = findMinIndex(arr, size, i);
    swap(arr, i, minIndex);
  }
}

int findMinIndex(int arr[], int size, int curInedx) {
  int minIndex = curInedx;
  for(int i = curInedx + 1; i < size; i++) {
    if(arr[i] < arr[curInedx]) {
      minIndex = i;
    }
  }
  return minIndex;
}

void swap(int* arr, int i, int j) {
  int temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
}
```


## Insertion Sort

```
_
2  4  5  3  1

next = 4
index = i
j = i
check if next < arr[j-1]

_  _  _  _
2  4  5  3  1

next = 3
index = 3
j = i
check if next < arr[j-1]

3 < arr[2]
3 < arr[1]
3 < arr[0]

- * - -
2 3 4 5

while(j > 0 and next < arr[j-1]) {
  arr[j] = arr[j-1]; // 2 4 5 5 -> 2 4 4 5
  j--
}

arr[j] = next; // 2 3 4 5
```

***

## Method to get const Object

The objects in the std::set are stored as const StudentT. So when you try to call getId() with the const object the compiler detects a problem, namely you're calling a non-const member function on const object which is not allowed because non-const member functions make NO PROMISE not to modify the object; so the compiler is going to make a safe assumption that getId() might attempt to modify the object but at the same time, it also notices that the object is const; so any attempt to modify the const object should be an error. Hence compiler generates error message.

```c++
 std::string Person::getName() const {
  return name;
}
```

***

## Vector with BubbleSort

```c++
// Function prototypes
void displayVector(vector<int>);
void sortVector(vector<int> &);

int main() {
  const int SIZE = 6;
  vector<int> values(SIZE);

  cout << "Please enter " << SIZE << " Integers separated by spaces. \n";
  for(int i = 0; i < SIZE; i++) {
    cin >> values[i];
  }

  cout << "\n The unsorted values entered are : \n";
  displayVector(values);

  sortVector(values);
  cout << "\n Sorted Vector are: \n";
  displayVector(values); 
  return 0;
}

/*********************************************************************
** Function:     sortVector(vector<int> &);
** Argument:  The reference(Address) of vector
** Return  :  Void. But it will use passing by reference to change 
**            the origin value of vector in the main function stack
*********************************************************************/

void sortVector(vector<int> &number) {
  int temp;
  bool swaped = false;

  do{
    swaped = false;
    for(int i = 0; i < number.size() - 1; i++) {
      if(number.at(i) > number.at(i+1)) {
        temp = number.at(i);
        number.at(i) = number.at(i+1);
        number.at(i+1) = temp;
        swaped = true;
      }
    }
  } while (swaped);
}

void displayVector(vector<int> number) {
  for(int i = 0; i < number.size(); i++) {
    cout << number.at(i) << endl;
  }
}

```

## Computational Problems and Basic Step
Input: Dose not mean a set of data entered by the user. It means the form of the data used by the algorithm solving the problem. 
Output: Means the result created by the algorithm that soves the problem.

## Asymptotic Complexity and the Big O Notation
### O(1)
A function f(n) is in this class if there is a constant K > 0 such that f(n) <= K for all n >= 1. An algorithm whose worst case complexity function is in this class is said to run in constant time.
 
### O(log2n)
Algorithm in this class run logarithmic time. A huge increase in the size of the problem results in only a small increase in the running time of the algorithm. (The Binary Search)

### O(n)
Algorithm in this class run in linear time. Any increase in the size of the problem results in a slight increase in the running time of the algorithm. Sequential search that make single pass, or a constant number of passes, over their input.

### O(nlogn)
The average case complexity of QuickSort and MergeSort.

### O(n^2)
Quadratic time. The performance is characteristic of algorithms that make multiple passes over the input data using two nested loops. The worst-case complexity funcitons of bubble sort, selection sort and QuickSort all lie in this case.

***

## Pointers
A variable that stores an address is called a pointer variable, but is often simply referred to as just a pointer. The definition of a pointer variable, say ptr, must specify the type of data taht ptr will point to.
```
int *ptr
```
'*' allows you to pass from a pointer to the variable being pointed to, it's called the indirection operator.

```
name   |ptr     |    x  |(address of x is 0x7300)
       --------- --------
value  |0x7300  |   25  |
```

You can use a pointer to indirectly access and modify the variable being pointed to. ptr could be used to change the contents of the variable x.

When the indirection opeartor is placed in front of a pointer variable name, it "deference" the pointers. When working with a deference pointer, you're actually working with the value the pointer is pointing to.

```c++
  int x = 10, userInput;
  int *ptr = &x;


  cout << "X equal to: " << *ptr << endl;
  cout << "Please input value to change x \n";
  cin >> userInput;

  *ptr = userInput;

  cout << "New Value is :" << *ptr << endl;
```

## The Relationship between arrays and pointers
Array name can be used as pointer constants, and pointers can be used as array names.

```c++
  int arr[] = {1,2,3,4};
  int* arrPtr = NULL;

  arrPtr = arr;

  for(int i = 0; i < 4; i++) {
    cout << *(arrPtr + i) << endl;
  }
```