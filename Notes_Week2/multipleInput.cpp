/*********************************************************************
** Author:       Wei-Chien Hsu
** Date:         04/09/18
** Description:  Asks the user enters width and height, and output
                 the Area.
*********************************************************************/

#include <iostream>
using namespace std;

int main() {
  float width, height;
  int area;

  cout << "Please enters the width and height (in float): " << endl;
  cin >>  width >> height;
  area = static_cast<int>(width * height);

  cout << "The area is : " << area << endl;
  return 0;
}