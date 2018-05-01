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


## Selection Sort

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