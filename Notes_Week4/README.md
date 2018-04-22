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


***
## Dynamic Memory Allocation 
程式執行到需要儲存處理的資料時才配置記憶體。

### 堆積(Heap)：
- 堆積是一種資料結構，用來存放電腦中沒有使用的記憶體，可自由配置(Free Store)。
- 使用new運算子配置空間，配置後會一直佔用空間直到使用delete運算子釋放空間為止
- new運算子和delete運算子通常是成對出現

```c++
  int *pInt = 0;
  pInt = new int(28);
  pInt = new int(27);
  cout << *pInt << endl;
  delete pInt;
```
- Allocating large chunks of memory
- Keep variable in the memory till the time we want

***