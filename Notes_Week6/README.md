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