/*********************************************************************
** Author:       Wei-Chien Hsu
** Date:         04/10/18
** Description:  This program will show how static local variable works. 
*********************************************************************/

 #include <iostream>
 using namespace std;

 void runThisFunction() {
   static int staticV = 0;
   cout << "Static Variable Value equals " << staticV++ << endl;
 }

 int main() {
   runThisFunction();
   runThisFunction();
   runThisFunction();
   runThisFunction();

   return 0;
 }
