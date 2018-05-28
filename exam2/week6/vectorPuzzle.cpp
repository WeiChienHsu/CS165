#include <iostream>
#include <vector>

void initializeBoolArray(bool arr[], int size);
bool vectorPuzzle(std::vector<int> vec);
bool vectorPuzzle(std::vector<int> vec, bool visited[], int current);

bool vectorPuzzle(std::vector<int> vec) {
  int num = vec.size();
  bool visited[num];
  initializeBoolArray(visited, num);
  return vectorPuzzle(vec, visited, 0);
}

bool vectorPuzzle(std::vector<int> vec, bool visited[], int current) {
  if(current < 0 || current >= vec.size()) return false;
  if(vec.at(current) == 0) return true;
  if(visited[current]) return false;
  visited[current] = true;
  return vectorPuzzle(vec, visited, current - vec.at(current)) || vectorPuzzle(vec, visited, current + vec.at(current));
}

void initializeBoolArray(bool arr[], int size) {
    for(int i = 0; i < size; i++) {
      arr[i] = false;
  }
}

int main() {
  std::vector<int> vec1;
  std::vector<int> vec2;

  vec1.push_back(2);
  vec1.push_back(4);
  vec1.push_back(5);
  vec1.push_back(3);
  vec1.push_back(1);
  vec1.push_back(3);
  vec1.push_back(1);
  vec1.push_back(4);
  vec1.push_back(0);
  
  vec2.push_back(1);
  vec2.push_back(3);
  vec2.push_back(2);
  vec2.push_back(1);
  vec2.push_back(3);
  vec2.push_back(4);
  vec2.push_back(0);   
  
  std::cout << vectorPuzzle(vec1) << std::endl;
  std::cout << vectorPuzzle(vec2) << std::endl;
  
  return 0;
}