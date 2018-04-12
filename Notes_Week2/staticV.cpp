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

 int square(int num);
 float square(float num);

 int main() {
   int numberInInteger;
   float numberInFloat;

   cin >> numberInInteger;
   cin >> numberInFloat;

   runThisFunction();
   runThisFunction();
   runThisFunction();
   runThisFunction();

   cout << square(numberInFloat) << endl;
   cout << square(numberInInteger)<< endl;
  
   return 0;
 }

 int square(int num) {
   return num * num;
 }

 float square(float num) {
   return num * num;
 }
