# Arrays


[C/C++ - Vector (STL) 用法與心得完全攻略
](http://mropengate.blogspot.com/2015/07/cc-vector-stl.html)

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
***