#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void printVec(int num) {
  cout << "Print: " << num << endl;
}

int main() {
  vector<int> vec;
  vec.push_back(20);
  vec.push_back(10);
  random_shuffle(vec.begin(), vec.end());
  for_each(vec.begin(), vec.end(), printVec);

  return 0;
}