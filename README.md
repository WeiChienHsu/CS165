# CS 165 Assignment

## How to Submit HW
- 
- Test on "flip" to make sure it works correctly in that environment. 
- Submit assignments on "Mimir".
- Remember that when you submit your project, you will only see results for the "visible" tests.  
- You won't see the results for the "hidden" tests until after the due date has passed.
- Always get your code working on flip before submitting it on Mimir - otherwise you're just wasting submissions, of which you only have five.

# Code Style Guidelines
- A comment block should appear at the top of every file 
- (at first each program will consist of just one file, but soon we'll be using multiple files for a single program)

```c
/********************************************************************* 
** Author: 
** Date:
** Description:
*********************************************************************/ 
```
- Every function should be preceded by a comment block, which describe the purpose of the function. 
- (when we get to classes and objects, "get" and "set" functions will be an exception to this rule)
- If a file contains only a single function, then the file comment block alone will suffice.

```c
/********************************************************************* 
** Description: "This function takes an integer parameter and returns true if that number is prime and returns false otherwise"
*********************************************************************/ 
```

### Comments
- Comments should describe what is happening, what parameters and variables mean, any restrictions or bugs, etc.  
- Other good places for comments include where the intention of a section of code might not be obvious,
- or where you had to make some kind of design decision. 
- Short comments should be what comments, such as "compute mean value", rather than how comments such as "sum of values divided by n". 

### Naming Conventions
- All names of variables, constants, functions and classes should be descriptive of their purpose.
- All variable names should start with a lower-case letter, with capital letters at the beginning of successive words that are part of the name, e.g. minScore, or clientFavoriteFood.
- Constant names and enum values should be in all caps, with an underscore separating successive words that are part of the name, e.g. STUDENT_ID_NUM.
- Function names should follow the same capitalization rules as variable names, e.g. binarySearch() or findMaxValue().
- Class names should begin with a capital letter, with additional capital letters at the beginning of successive words that are part of the name, e.g. Student, or SalariedEmployee.

### General Readability
- Lines should be kept to a decent length. Don't try to do too much in a single line.
- Functions also should be kept to a decent length - if a function is getting too long, you may want to break it up into multiple functions.
- Always use proper indentation to indicate the structure of your code.
- Use one space to separate logical chunks within a function. Use two or three spaces between functions.

### Other
- Do not use any global variables.
- There are several numeric types available.  For the assignments, use int for integer types and double for floating point types.