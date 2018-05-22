#include <iostream>
#include <string>

using namespace std;

template <class T1, class T2, class T3>
void echoAndReverse(T1 a1, T2 a2, T3 a3) {
  cout << a1 << " : " << a2 << " : " << a3 << endl;
  cout << a3 << " : " << a2 << " : " << a1 << endl; 
}

int main() {
  echoAndReverse("abc", "def", "hij");
  return 0;
}