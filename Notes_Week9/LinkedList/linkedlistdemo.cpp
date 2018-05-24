#include <iostream>
using namespace std;

struct ListNode {
  double value;
  ListNode *next;
  ListNode(double val, ListNode *next = nullptr) {
    this->value = val;
    this->next = next;
  }
};

int main() {

  ListNode *head = new ListNode(12.5);
  head = new ListNode(10, head);
  head = new ListNode(5, head);

  ListNode *ptr = head;
  while(ptr != nullptr) {
    cout << ptr->value << " ";
    ptr = ptr->next;
  }

  head = new ListNode(2, head);
  
  ListNode *ptr_new = head;
  cout << ptr_new->value  << endl; 
  
  cout << endl;

  // cout << "First Item: " << head->value << endl;
  // cout << "Second Item " << head->next->value << endl;
  // cout << "Third Item " << head->next->next->value << endl;
  return 0;
}
