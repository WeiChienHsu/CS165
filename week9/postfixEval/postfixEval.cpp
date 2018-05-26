/*********************************************************************
** Author:       Wei-Chien Hsu
** Date:         05/25/18
** Description:  A function named postfixEval that uses a stack<double> to evaluate postfix expressions.
                 It should take a "C-style string parameter" that represents a postfix expression.
                 The only symbols in the string will be +, -, *, /, digits and spaces.
                 The return type should be double.

** Example    :  "25 12 7 - 2 * /"
 --------
| 25 12 7     : We put all digits into the stack in order
 --------
 --------
| 25 12 7     : Meet "-", pop out 7 and 12, 12 - 7 = 5, push 5 back into the Stack  
 --------
 --------
| 25 5 2      : Put 2 into the Stack  
 --------
 --------
| 25 5 2      : Meet "*", pop out 5 and 2, 5 * 2 = 10, push 10 back into the Stack
 --------
 --------
| 25 10       : Meet "/", pop out 25 and 10, 25 * 10 = 2.5, push 2.5 back into the Stack
 --------
 --------
| 2.5         : The end, return the top element 2.5 as result in this function
 --------
*********************************************************************/
#include <iostream>
#include <stack> // stack
#include <cstring>
#include <cstdlib> // atof

double postfixEval(char expression[]) {
  // Initialize the Stack
  std::stack<double> postfixStack;
  /************************************************************
  ** Use "strtok" function to strim the char array
  ** and could get the specific digits or operators
  ** By using a pointer points to the array
  ** Example: "25 12 7 - 2 * /" get 25, 12, 7, -, 2, *, / in order
  **
  ** std::strtok(expression, " ") with std::strtok(nullptr, " ") for iteration
  *********************************************************************/

  char *charPtr = std::strtok(expression, " ");
  /************************************************************
  ** Algorithm:
  ** 1) Meet ndigits, push it into the stack
  ** 2) Meet operators: pop out two digits from the stack and named then first and second in order
  ** +: result = first + second
  ** -: result = first - second
  ** *: result = first * second
  ** /: result = first / second
  *********************************************************************/
  double first = 0;
  double second = 0;
  double result = 0;
 
  while(charPtr != NULL) {
    // atof(charPtr) could transfer the pointed number into double
    // 2 1 7 2 -> 25 12 7 2
    if(*charPtr >= '0' && *charPtr <= '9') {
      postfixStack.push(std::atof(charPtr));
    } else {
      // The top element is the second element
      second = postfixStack.top();
      postfixStack.pop(); 

      // In the Deque implemented Stack, we need to use pop to remove the top element
      // After removing the second element, we got the first element
      first = postfixStack.top();
      postfixStack.pop();

      if(*charPtr == '+') {
        result = first + second;
      } else if(*charPtr == '-') {
        result = first - second;
      } else if(*charPtr == '*') {
        result = first * second;
      } else if(*charPtr == '/') {
        result = first / second;
      }

      // Push back the result
      postfixStack.push(result);
    }
    // Get the next trimmed digit or operator in the expression array
    charPtr = std::strtok(NULL, " ");
  }
  return postfixStack.top();
}