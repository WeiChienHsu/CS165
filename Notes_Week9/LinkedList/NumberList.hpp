#include <iostream>
using namespace std;

class NumberList {
  protected:
    // Declare a class for the lust node
    struct ListNode {
      double value;
      ListNode *next;
      ListNode(double value, ListNode *next = nullptr) {
        this->value = value;
        this->next = next;
      }
    };
    ListNode *head;
  
  public:
    NumberList() { head = nullptr; }
    ~NumberList();
    void add(double);
    void remove(double);
    void displayList() const;
}


