# Arrays


[C/C++ - Vector (STL) 用法與心得完全攻略](http://mropengate.blogspot.com/2015/07/cc-vector-stl.html)

[真的很可怕的C語言](http://pl-learning-blog.logdown.com/posts/1060530)

[Pointers and dynamic memory - stack vs heap](https://www.youtube.com/watch?v=_8-ht2AKyH4)

***

## Chapter 8

- Remember that the size of an array must be known at compile time, which means that when you declare an array, you can't specify its size with a variable.  There is a way of dynamically allocating memory for an array, which you'll learn about in chapter 10.  (Actually g++ allows you to use a variable to specify the size of an array, but that goes against the C++ standard.)

- Always remember that the elements of an array (and the characters of a string) are numbered starting from zero.
For loops work very nicely for doing something with each element of an array.

- I don't think parallel arrays are usually a good idea.  You have to remember to make changes in multiple places - for instance, if you delete one of the elements of an array, you have to remember to delete the corresponding element from any arrays "parallel" to that one.  A better idea is to use an array of structs, or possibly objects.
Remember that when you pass an array to a function, you're really passing the address of the array.  You'll learn more about this in chapter 10.

- When you pass an array to a function you cannot use a range-based for loop on that array.  The technical reason is that an array that is passed to a function "decays" to a pointer, causing it to lose information about the array that the range-based for loop requires.

- The text isn't totally clear on this, but the capacity and size of a vector are two different things.  A vector's capacity is how many elements are currently set aside for it.  A vector's size is how many elements are currently in use (have something stored in them).

- It's better to access elements of vectors using the at() method instead of the square brackets used for arrays.  The reason is that the at() method will generate an error if you try to access outside the bounds of the vector, whereas if you use array notation the behavior in that case is undefined.

## Chapter 10

- The most important thing to understand about pointers is that they are still just variables.  An int variable is a little piece of memory set aside to hold an integer value.  A pointer-to-int is a little piece of memory set aside to hold the address of an int variable.  When a description says that a pointer "points to" a variable, it just means that the pointer is storing the address of that variable.  When you "dereference" a pointer, you are just saying that instead of using the pointer, you're using the variable whose address is stored in the pointer.
You should not normally need to use pointer arithmetic, but you should still understand it.

- Be careful not to confuse the use of '&' for passing by reference with its use as the "address of" operator.  They are two separate things.  When you see it on the right hand of an assignment, or as an argument in a function call, it means "address of".  When you see it in the parameter list of a function header, it means that you're passing by reference.

- Only memory which was dynamically allocated with "new" needs to be freed with "delete".

***


## Static Array

```c
#include <iostream>
#define ELE 5

int main() {
  int arr[ELE];

  std::cout << "Array Locatoin : " << arr << std::endl;
  std::cout << "Array Pointer Location : " << &arr << std::endl;
  std::cout << "Array Default Value : " << arr[0] << std::endl;
  return 0;
}
```

```
Array Locatoin : 0x7ffee8cff8e0
Array Pointer Location : 0x7ffee8cff8e0
Array Default Value : 0
```

- Self-ref pointer for static array
- So we could not change the content


## Segmentiaion Falut
If you get a little bit out of arry, there will be a 

```
Segmentation fault: 11
```

## Pointer
In order to change memory location values outside of your function. 
Anthing outside a fucntion parameters is the address of.

- "*" Dereference Operator: Take to the contents at that memory location 
(對該position的variable或Object進行操作，讀值賦值)

- "&" Address-Of Operator: Take the address of Variable of Object

- init: type *pointer = 0 必須給予某個位置，不然後續會有問題

- 變數指標擁有的值，就是指向的對象的地址，變數指標自己也有存在不同的地址內，使用變數指標存儲的地址，才可以更改該地址內的變數或讀取。

```c++
int b; 
//跟記憶體要一塊區域稱為b,這塊區域專門放int型變數值
 
b = 2; 
//把2這個值給變數b
 
int* pointer; 
//跟記憶體要一塊區域稱為pointer, 這塊區域專門放指向int型變數的指標（地址）
 
pointer = &b; 
//把變數b的地址值給pointer，注意不能寫成 pointer = b;
```
- 變數 b 在記憶體中對應了一塊儲存空間，而這塊儲存空間總有一個起始的地址。所以 pointer 對應到的就是這個起始地址。

在這種狀況下，就可以用「*pointer」來拿到這個變數。

這裡的「*」，和宣告指標變數的 int* pointer 的意義不太一樣。反而是和「&」相對應——「&」代表「取出地址」、「*」代表「取出內容」。

等等，那所謂的「*pointer 取出的內容」指的到底是變數 b、還是變數 b 的值 2？

這兩個是不同的東西喔！變數 b 是這塊區域，2 是值。

答案是：*pointer 代表的就是變數 b。所以我們可以把 *pointer 當作變數 b 來使用。

```c++
#include <stdio.h>
 
int main(void) {
    int b = 2;
    int* pointer = &b;
 
    printf("變數 b 的值：%d\n", b);
    printf("變數 b 的地址：%p\n", &b);
    printf("pointer 的值：%p\n", pointer);
    printf("\n"); //換行
    
    *pointer = 100;
 
    printf("*pointer 的值：%d\n", *pointer);
    printf("變數 b 的值：%d\n", b);
    printf("變數 pointer 的地址：%p\n", &pointer);
 
    return 0;
}
```
### Output

```
變數 b 的值：2
變數 b 的地址：0x7ffee58578f8
pointer 的值：0x7ffee58578f8
pointer 的地址: 0x7ffee58578f0

*pointer 的值：100
變數 b 的值：100
變數 pointer 的地址：0x7ffee58578f0
```


***

## Why pointer varaible is a strong type
- We don't use pointer just for storing the address in memory.
- We also use piinters to dereference these address so we can access or modify these address.
- Datatype have different size, for 32bit device, int stored in 4 byte, char stored in 1 byte, float stroed in 4 byte
- If we define a int pointer, when we dereference that address, the machien knows that it needs to look up from this memory to next 3 address for a real value.


## Pointer to Pointer
- When we want a pointer to pointer
- Since the pointer variable is a strong stype variable, the "point to" value to the q pointer should be "int*" which is the type of pointer p.

```
_________________________
a=5  | p = 200  |  q = 201
__________________________
200    201        202

int *p = &5 -> pointer p stored the address of a (which is 200)
int* *q = &p -> pinter q stored the address of pointer p

```


## Pointer with Array

- pointer++ Could let the pointer points to the next position in the Array.

如果是普通的整數型變數的話++就是+1了。但是，指標變數pnumber給++的話，並不是單純的+1。因為pnumber是int的指標變數，所以pnumber所指的地方也是有int的大小(32bit電腦通常是4bytes)，也就是說，如果把位址只加上1的話，會指向奇怪的地方。這也是為何位址不能用普通的int來儲存的原因

```c++
  int intArray[3]= {1,2,3};
  int *pInt = intArray;
  cout << "Array address: " << pInt << endl;
  cout << "First number in Array: " << *pInt << endl;
  pInt++;
  cout << "Array address: " << pInt << endl;
  cout << "Second number in Array: " << *pInt << endl;
```
```
Array address: 0x7ffee007f93c
First number in Array: 1
Array address: 0x7ffee007f940
Second number in Array: 2
```

## 2D Array and Pointer
### A value of type "int (*)[4]"
- A value of type "int (*)[4]" cannot be used to intitialize an entity of type "int *"
```c++
int arr[2][4] = {{0,2,4,6},{1,1,1,1}};
int *pint3 = arr;
```
- Instead, we use (*pInt)[4] = inMulAr;
```c++
int (*pint3)[4] = arr;
```

C++中，陣列變數會有陣列型別和大小的資訊，所以要宣告和多維陣列相同型別的指標時，也需要型別和大小的資料
- 格式：型態 (*變數名稱)[大小] = 陣列名稱;
如果變數名稱外沒有小括號，編譯器會將型別和*合在一起解讀成記錄指標的陣列
- 格式：型別* 變數名稱 [大小] = 陣列名稱;

## Function and Pointer
- Since if we use a function, all local values or variables will be stored in a separated Stack in the memory.
- We could pass an address of the variable as a argument to a pointer in another function.
- Pointer of integer and the value that is passed to this particular address of variable.
```c++
void increment(int* p) {
  *p = *p + 1;
}

int main() {
  int a = 10;
  increment(&a);
}
```


```c++
int sum(int *, int *);

int sum(int *a, int *b) {
  int value;
  value = *a + *b;
  return value;
}

int main() {
  int num_1 = 1, num_2 = 2, answer;

  answer = sum(&num_1, &num_2);
  std::cout << answer << std::endl;
  return 0;
}
```
### Pass an array as an argument into FUNCTION
- When compiler see a fucntion as argument, it doesn't copy whole array.
- It just creates a pointer variable by the same name instead of creating the whole array
- Compiler just copied "the address of first element" in the array

```
int SumOfElement(int A[]) --> int* A
```

- Since array could be a large exist, it doesn't necessary to copy whole array

```c++
int SumOfElements(int *A, int size) {
  int i, sum = 0;
  cout << "Size of A[] in sum function: " << sizeof(A) << endl;
  for(i = 0; i < size; i++) {
    sum += A[i];
  }
  cout << "Size of A[0] in sum function: " << sizeof(A[0]) << endl;
  return sum;
}

int main() {
  int A[] = {1,2,3,4,5};
  int size = sizeof(A) / sizeof(A[0]);
  cout << "Size of A[] in main function: " << sizeof(A) << endl;
  cout << "Size of A[0] in main function: " << sizeof(A[0]) << endl;
  cout << "Sum of the Array: " << SumOfElements(&A[0], size) << endl;
  cout << "Sum of the Array: " << SumOfElements(A, size) << endl;
  return 0;
}
```

## Pointers and multi-dimensional Arrays
- Collection of Arrays

```
C[i][j][k] = *(C[i][j] + k) = *(*(C[i] + j) + k) = *(*(*(C + i) + j) + k)
```

#### For 2-D Array
```
B[i][j] = *(B[i] + j) = *(*(B + i) + j)
--------------------

B[2][3] = *(B[2] + 3) // 先指向B的第二個1D Integer Array，再從開頭往後指三個
= *(*(B + 2) + 3) // 先指向B的初始element，向後兩個2D Integers Array，指向該1D Integer Array的第一個後，再從開頭往後指三個
```

#### Example

```
 400                  412  
----------------------------------------
|  0 |  1   |  2   ||  5  |  6  |   7  |   
----------------------------------------
       404    408          416    420

int B[2][3]

int* p = b -> WRONG! pointer points to 1-D array of "3 Integers"
int (*p)[3] = B -> B stand for the address of this 2D Array

B will return int*[3] 在大格子裡移動，一次move 3 integers

print B || &B[0]  :  400 (Address of B[0] -> Fisrt element in the 3 integers Array)
print *B || B[0]  :  400 (Address of B[0][0] -> First element in the Whole Array)

==============

B[0] will return int* 小格子裡，一次move 1 integer

print B + 1 || &B[1] : 412
print *(B + 1) || B[1] || &B[1][0] : 412

==============

print *(B + 1) + 2 || B[1] + 2 || &B[1][2] //420
print *(*B + 1) || B[0][1] //1 

```

***

## Dynamic Memory Allocation 
程式執行到需要儲存處理的資料時才配置記憶體。



## Memory
The memory that is assigned to a program or application, the typical architrcture can be devided into four segments.
- Code(Text) : Instructions need to be executed

- Static/Global variables: Variables taht are not declared indside a function, the that have a whole lifetime of an application, they are accesible anywhere during the runtime.

### Stack

- Stack: Stored all function calls and all the local variables. Local variables are created inside function and they live only till the time the function is executing. (From main funciton, put all the function in to different stack frams and step by step execute them). When the function size is larger than stack conpacity(Bad Recursion), it will cause a stack overflow.

- When the funciton is called, it is pushed onto the top of stack, when it finished, it is pop out of stack and it's not possible to manipulate the scope of a variable if it is on stack.

- If we would like to have a large size of array in function as local variable, then we need to know the size of the array at compile time only. If we have a scenario like we have to decide how large the array will be based on some parameter during runtime the it has some problems: Allocating large chunks of memory of keeping variable in the memory till the time we want.

### Heap :
- Heap: Will chagne the size during lifetime of application. (Not likes the Code/Stack and Static)
- Programmer couldl control using Heap in system.(Large pool of memory)
- 堆積是一種資料結構，用來存放電腦中沒有使用的記憶體，可自由配置(Free Store)。
- 使用new運算子配置空間，配置後會一直佔用空間直到使用delete運算子釋放空間為止
- new運算子和delete運算子通常是成對出現。

```c++
  int a; // Goes on stack
  int *pInt;
  pInt = new int[20];
  delete[] pInt;
```
- Pointer's address save in the stack and points to the array stored in Heap(which assumes from 50 to 130)


## Memory Leak 

***

## Pointers as Function Reutrns


```c++
int Add(int *a, int *b) {
  // a and b are pointers to integers stored in loacl "Add"
  // int *a = &a;

  cout << "Address of a in Add = " << &a << endl; 
  // &a : 0x7ffee5a328b8 is pointer

  cout << "Value in a of Add(address of a of main) = " << a << endl;  
  // a: 0x7ffee5a32918 Pointer points to address of a
  
  cout << "Value at address stored in a of Add = " << *a << endl; 
  // *a: Value of a stored in the main function -> 4
  
  int c = *a + *b;
  return c;
}

int main() {
  int a = 4, b = 6;
  cout << "Address of a in Main = " << &a << endl; // 0x7ffee5a32918
  int sum = Add(&a, &b);
  cout << sum << endl;
  return 0;
}
```
#### But when we want to return the pointer variable from function :
- If we try to return a local variable from the called function back to the calling function(Main function), when called function finished and the control returns back to calling function that memory has already been de-allocated.
- It is ok to pass loacl variables from bottom to top (In stack).

```c++
int *Add(int *a, int *b) {
  int c = *a + *b;
  return &c;
}

int main() {
  int a = 4, b = 6;
  int *ptr = Add(&a, &b);
  cout << *ptr << endl;
  return 0;
}
```

```
warning: address of stack memory associated with local variable 'c' returned [-Wreturn-stack-address]
```
- Solve the problem by stored the value into Heap (Which could manaully control the value saved in memory)
- 我們將 Add function 內的 C 變成一個 pointer ， 指向Heap中的某個位置，在Add function 運行結束後，該值會繼續存在 Heap 當中，回傳值就是 C pointer 指向的位置。
- Main function 內的 Pointer 指向的即是剛才 Heap 中的位置，可以直接取值。

```c++
int *Add(int *a, int *b) {
  int *c = new int; // New a space in Heap
  *c = *a + *b; // Value in the C will be the sum of Value of Address a and b
  return c;
}

int main() {
  int a = 4, b = 6;
  int *ptr = Add(&a, &b); // Pointer points to the C stored in the Heap memory 
  cout << *ptr << endl;
  return 0;
}
```
```
Address of C in Heap:(from Add function) 0x7fa179402810
Address of pointer which save the address of C in Heap (from Add function) 0x7ffee352c8f8
Address of C in Heap (from Main Function)0x7fa179402810
```

## Function Pointers
Stored the Address of "Function".
- Which mean the starting point of the block of memory containing all the instruction in a function.
- Pointer should take arguments the same as in the function.

#### Pointer take the address of Add

```c++
int Add(int a, int b) {
  return a + b;
}

int main() {
  int c;
  int (*p)(int, int);
  p = &Add;
  c = (*p)(4,5);
  cout << c << endl;

  return 0;
}
```
- Only assign a Function also return the address of Function in this case
```c++
  p = Add;
  c = p(4,5);
```

## Function Pointers and Callbacks
A is a callback function. It can be called back by B through the reference through the function pointer.

```c++
void A() {
  cout << "Call Back Function was called!" << endl;
}

void B(void (*ptr)()) { // Function pointer as argument
  ptr(); // Call back functino that 'ptr' points to
}

int main() {
  B(A); // A is callback function
  return 0; 
}
```

### Why pass a function 

Lets say you are designing a library function that would do something like sorting so anyone can just use your library function and sort. And you want to keep this sorting function generic , so data type can be anything. Then, how would you take the required information to sort from user of your library function?  You cannot guess the comparison logic for a complex daya type. So, you would want to get the comparison logic too which can be passed as a function. So, in many cases when we are dealing with generic scenarios, function pointers make our life easier. It should be seen as a way to accept functionality as argument. So far, we knew that functions can accept only data, but now we know that even a function can be passed.

### Case 
- Sorting
- Callback function should compare two integers, should return 1 if first element has higher rank, 0 is elements are equal and -1 if second element has higher rank.

```c++
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
```

***

# Static and Dynamic 2D Array

### 1D Static Array
Self-referencial constant pointer, could change the value

Array Location : 0x7ffeef18f910
Array pointer location : 0x7ffeef18f910


### 1D Dynamic Array
int *array pointer, not self-referencial pointer

Array Location on the Heap : 0x7fb337d00000 (in Heap)
Array pointer location : 0x7ffeef18f8b8 (in main function)


```c++
int main() {
  int arr[ELE];
  int i, size;


  cout << "Array Location : " << arr << endl;
  cout << "Array pointer location : " << &arr << endl;

  for(i = 0; i < ELE; i++) 
    arr[i] = i;
  
  for(i = 0 ;i < ELE; i++)
    cout << "Initial contnets: " << arr[i]  << " | Address of elements: " << &arr[i] << endl;

  
  int *dynarr;
  dynarr = new int[ELE];
  cout << "Array pointer location : " << &dynarr << endl;
    cout << "Array Location on the Heap : " << dynarr << endl;

  for(i = 0; i < ELE; i++) 
    dynarr[i]   =  i;

  for(i = 0 ;i < ELE; i++)
    cout << "Initial contnets: " << dynarr[i] << " | Address of elements in Heap: " << &dynarr[i]<< endl;

  delete[] dynarr;

  return 0;
}
```


### 2D Static Array


### 2D Dynamic Array