#include "NumberList.hpp"
using namespace std;

/*****************************
 * Add adss a new element to the
 * end of the list
******************************/
void NumberList::add(double number) {
  if(head == nullptr) {
    head = new ListNode(number);
  } else {
    // The list is not empty
    // Use Nodeptr to traverse the list
    ListNode *nodePrt = head;
    while(nodePrt->next != nullptr) {
      nodePrt = nodePrt->next;
    }

   // nodePrt->next is nullptr so nodePtr points to last node
   // Create a new node and put it after the last node
   nodePrt->next = new ListNode(number);
  }
}

/*****************************
 * Traversal(display) a sequence of all values
 * currently stored in the list.
******************************/
void NumberList::displayList() const {
  ListNode *nodePtr = head; // Start at head of list
  while(nodePtr != null) {
    cout << nodePtr->value << "  ";
    nodePtr = nodePtr->next;
  }
}

/*****************************
 * Destructor deallocates the memory used by the list
******************************/
NumberList::~NumberList() {
  ListNode *nodePtr = head; // Start at head of list
  while(nodePtr != nullptr) {
    // garbage keeps track of node to be delete
    ListNode *garbage = nodePtr;
    nodePtr = nodePtr->next;
    delete garbage;
  }

}