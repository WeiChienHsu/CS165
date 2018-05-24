#include "NumberList.hpp"
#include <iostream>

/*****************************
 * Struct ListNode Constructpt
******************************/

NumberList::ListNode::ListNode(double val, ListNode *next = nullptr) {
  this->value = val;
  this->next = next;
}

/*****************************
 * Default Constructor
******************************/
NumberList::NumberList() {
  this->head = nullptr;
}

/*****************************
 * Copy Constructor
******************************/
NumberList::NumberList(const NumberList &obj) {
  if(obj.head == nullptr) {
    this->head = nullptr;
  } else {
    this->head = new ListNode(obj.head->value);
    ListNode *cur = this->head;
    // ListNode *objHead = obj.head;
    // ListNode *objCur = objHead;
    ListNode *objCur = obj.head;
    while(objCur->next != nullptr) {
      cur->next = new ListNode(objCur->next->value);
      objCur = objCur->next;
      cur = cur->next;
    }
  }
}

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
  while(nodePtr != nullptr) {
    std::cout << nodePtr->value << "  ";
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


/*****************************
 * Removing an Element
 * Function doesn't assume the lust is sorted
******************************/
void NumberList::remove(double number) {
  ListNode *nodePtr, *previousNodePtr;

  // If the list is empty, do nothing
  if(!head) return;

  // Determine if the first node is the one to delete
  if(head->value == number) {
    nodePtr = head;
    head = head->next;
    delete nodePtr;
  } else {
    // Initialize nodePtr to the head of the list
    nodePtr = head;

    // Skip nodes whose value is not number
    while(nodePtr != nullptr && nodePtr->value != number) {
      previousNodePtr = nodePtr;
      nodePtr = nodePtr->next;
    }

    // When nodePtr != null, means the number is in the list
    // Link the previous node to the node after nodePtr, then delete nodePtr 
    if(nodePtr != nullptr) {
      previousNodePtr->next = nodePtr->next;
      delete nodePtr;
    }
  }
}

int main() {
  NumberList list;
  list.add(10);
  list.add(20);
  list.add(30);
  list.displayList();
  
  NumberList list2(list);
  list2.displayList();
  return 0;
}