/*********************************************************************
** Author:       Wei-Chien Hsu
** Date:         04/10/18
** Description:  User enters their salary plans either hourly or annual.
                 And we wiil ask their detail information to count their
                 weekly payment.
                 - Annual : Ask their annual salary / 52
                 - Hourly: Ask their total working hours and hourly payment
*********************************************************************/

 #include <iostream>
 using namespace std;

  char readSelection() {
    char selection;
    cin >> selection;

    while(selection != 'A' && selection != 'a' 
          && selection != 'H' && selection != 'h') {
            cout << "Please enter A or H: " << endl;
            cin >> selection;
          }

    return selection;

  }

  float calWeeklyPaid(float annual) {
    return annual / 52.0;
  }

  float calWeeklyPaid(int workHour, float houly ) {
    return workHour * houly;
  }

  int main() {
    float weeklyPaid, annualPaid, houlyPaid ;
    int workHours;
    char selection;
    // Ask user's payment type
    cout << "Please enter A or H : " << endl;
    cout << "A: Annual Plan" << endl;
    cout << "H: Hourly Plan" << endl; 

    // Read user's payment type and assign to 
    // different function to count the weekly payment

    // Check the input
    selection = readSelection();

    switch(selection){
      case 'A':
      case 'a':  cout << "How much is your annual income: " << endl;
                 cin >> annualPaid;
                 cout << "The weely pay is: $" ;
                 cout << calWeeklyPaid(annualPaid) << endl;
                 break;
      case 'H':
      case 'h':  cout << "How many hour you worked a week: " << endl;
                 cin >> houlyPaid;
                 cout << "How many hourly payment you got: " << endl;
                 cin >> workHours;
                 cout << "The weekly pay is: $" ;
                 cout << calWeeklyPaid(workHours, houlyPaid) << endl;
                 break;
    } 

    return 0;
  }