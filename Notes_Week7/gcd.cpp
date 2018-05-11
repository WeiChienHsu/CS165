#include <iostream>
using namespace std;


// gcd(x, y) = gcd(y, x%y) -> if x % t == 0, y us gcd
int gcd(int x, int y) {
    if(x % y == 0) {
      return y;
    }
    return gcd(y, x % y);
}


int main() {
  cout << gcd(12, 18) << endl;
}