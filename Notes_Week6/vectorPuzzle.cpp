/*********************************************************************
** Author:       Wei-Chien Hsu
** Date:         05/02/18
** Description:  


*********************************************************************/


#include <iostream>
#include <vector>

bool vectorPuzzle(std::vector<int> &vec, int current, bool visited[]);
bool vectorPuzzle(std::vector<int> &vec);
void initializeBoolArray(bool arr[], int size);



/*************************************************************
** initializeBoolArray(bool arr[], int size)
**
**************************************************************/

void initializeBoolArray(bool arr[], int size) {
    for(int i = 0; i < size; i++) {
      arr[i] = false;
  }
}

/*************************************************************
** bool vectorPuzzle(std::vector<int> &vec)
**
**************************************************************/

bool vectorPuzzle(std::vector<int> &vec){
  bool visited[vec.size()];
  initializeBoolArray(visited, vec.size());
  return vectorPuzzle(vec, 0, visited);
}

/*************************************************************
** bool vectorPuzzle(std::vector<int> &vec, int current, bool visited[])
**
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