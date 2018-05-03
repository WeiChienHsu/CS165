/*********************************************************************
** Author:       Wei-Chien Hsu
** Date:         05/02/18
** Description:  We have a token that starts on the leftmost square.  
                 On each turn, the token can shift left or right a number 
                 of squares equal to the value in its current square, 
                 but is not allowed to move off either end.(Boundry)

                The goal is to get the token to the rightmost square 
                (that contains zero).  This row has a solution (more than one), 
                but not all rows do. 

** Example    :  [2, 4, 5, 3, 1, 3, 1, 4, 0] -> Return :true
                 [1, 3, 2, 1, 3, 4, 0] -> Return :false
** Remind     : free to use helper methods for any of these projects, meaning 
                that you can write a function that takes the specified parameters 
                and have it call your recursive function with any additional 
                parameters it needs.
*********************************************************************/


#include <iostream>
#include <vector>


/*************************************************************
 *  Functions prototype
**************************************************************/


bool vectorPuzzle(std::vector<int> &vec, int current, bool visited[]);
bool vectorPuzzle(std::vector<int> &vec);
void initializeBoolArray(bool arr[], int size);


/*************************************************************
** initializeBoolArray(bool arr[], int size)
** This function initialize the Bool Array with fasle values
** Since the initilize in vectorPuzzle function, we couldn't
** make sure all values are false, so need an additional method
** to deal with it.
**************************************************************/

void initializeBoolArray(bool arr[], int size) {
    for(int i = 0; i < size; i++) {
      arr[i] = false;
  }
}

/*************************************************************
** bool vectorPuzzle(std::vector<int> &vec)
** This function takes a vector of ints as a parameter and returns true if the 
** puzzle is solvable for that row, but returns false otherwise.
**************************************************************/

bool vectorPuzzle(std::vector<int> &vec){
  bool visited[vec.size()];
  initializeBoolArray(visited, vec.size());
  return vectorPuzzle(vec, 0, visited);
}

/*************************************************************
** bool vectorPuzzle(std::vector<int> &vec, int current, bool visited[])
** Recursive function:
** We need to make sure our current index:
** 1. Not fo out of the boundry : current < 0 or current excesse vector size.
** 2. Do not visit the place we had already visited : Used a bool array to record
** 3. Mark the place we just visited : Assign a true value into bool array
** 4. If the current Value is 0, which means we meet the target, return true
** Recursion:
** In each level, we could have two decision going forward or back, so we could
** use a recursive function to check our next level, if there is a true return
** value, it means we coudl reach the last number, if we only met the false 
** situation I've mention above, we will get a all false values reutrn.
**************************************************************/

bool vectorPuzzle(std::vector<int> &vec, int current, bool visited[]) {
 
  // Out of the boundry
  if(current < 0 || current >= vec.size()) {
    return false;
  }
  // Point to the Target 0
  if(vec.at(current) == 0) {
    return true;
  }
  // Re-visit the same point means there is an infinite loop
  if(visited[current]) {
    return false;
  }
  // Cache the visited index
  visited[current] = true;

  // Return the results of next steps, 
  // when there exists one of the True boolean value, means it could touch the target
  // By the defintion of OR operator, we know it could handle the results

  return vectorPuzzle(vec, current + vec.at(current), visited) || vectorPuzzle(vec, current - vec.at(current), visited);
}


int main() {
  std::vector<int> vec;
  vec.push_back(1);
  vec.push_back(3);
  vec.push_back(2);
  vec.push_back(1);
  vec.push_back(3);
  vec.push_back(4);
  vec.push_back(0);
  // vec.push_back(4);
  // vec.push_back(0);
  
  if(vectorPuzzle(vec)) {
    std::cout << "true" << std::endl;
  } else {
    std::cout << "False" << std::endl;
  }

  return 0;
}