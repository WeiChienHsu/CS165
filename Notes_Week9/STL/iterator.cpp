#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <class T>
void print(T begin_iter, T end_iter) {
  auto iter = begin_iter;
  while(iter != end_iter) {
    cout << *iter << " ";
    iter++;
  }
  cout << endl;
}

int main() {
  string names[3];
  names[0] = "Kevin";
  names[1] = "Kevin!!";
  names[2] = "Peter";
  print(begin(names), end(names));

  vector<int> vec;
  vec.push_back(10);
  vec.push_back(20);
  vec.push_back(30);

  print(begin(vec), end(vec));
  
  return 0;
}