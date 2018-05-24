#include <iostream>
using namespace std;

struct ListNode {
  double value;
  ListNode *next;
};

int main() {
  ListNode *head = nullptr;

  // Creat First Node with 20.0
  head = new ListNode;
  head->value = 20.0;
  head->next = nullptr;

  // Create Second Node with 12.5
  ListNode *secondPtr = new ListNode;
  secondPtr->next = nullptr;
  secondPtr->value = 12.5;
  head->next = secondPtr;

  // Print 
  cout << "First item is " << head->value << endl;
  cout << "Second item is " << head->next->value << endl;
  cout << "\n";
  cout << "Address of head Pointer: " << &head << endl;
  cout << "Address of head Pointer point to: " << head << endl;
  cout << "is Equal to 'Address of First Value': " << &head->value << endl;
  cout << "The pointer in the First Node is loacted nearby the Value: " << &head->next << endl;
  cout << "is Equal to 'Address of First Value': " << &head->next->value << endl;
  return 0;
}