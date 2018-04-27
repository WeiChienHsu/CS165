# Chapter 9

- Insertion sort is another sorting algorithm.  Like bubble sort and selection sort its worst-case time is O(n2),but it has a different best-case.  When the values are already nearly sorted, insertion sort runs in O(n).

- Quick sort, as its name would suggest, is one of the faster sorting algorithms.  There are other algorithms with - a better worst-case complexity - merge sort and heap sort both run in O(n lg n) worst-case, whereas for quick sort the worst-case is O(n2), the same as bubble sort!  However the average running time for quick sort is O(n lg n), and its worst case is highly improbable, so it's still a fast algorithm.

- Big-O doesn't tell you how much actual time an algorithm will take.  It tells you how quickly that time increases as the size of the input increases.

- In addition to time complexity, you can also compare the space complexity of different algorithms, which concerns how much additional space an algorithm needs to use.  There is often a tradeoff between the amount of time and the amount of space an algorithm requires.

- In coding interviews you'll be expected to be able to talk about running times.  They'll ask you to figure out the code for something on a white board and often they'll ask you about its running time and whether you can think of a way to do it that uses less time or memory.


## Selection Sort

## Bubble Sort

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