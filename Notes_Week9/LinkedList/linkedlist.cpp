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

  // Create Third Node with 10
  ListNode *thirdPtr = new ListNode;
  thirdPtr->next = nullptr;
  thirdPtr->value = 10.0;
  head->next->next = thirdPtr;

  // Print 
  cout << "First item is " << head->value << endl;
  cout << "Second item is " << head->next->value << endl;
  cout << "Third item is " << head->next->next->value << endl;
  return 0;
}