#include <iostream>
using namespace std;

struct contact_info{
  string name;
  int phone;
};

contact_info create_contact() {
  contact_info contact;
  contact.name = "Kevin";
  contact.phone = 123;
  return contact;
}

int main() {
  contact_info contactOne;
  contactOne = create_contact();

  cout << contactOne.name << endl;
  
}

