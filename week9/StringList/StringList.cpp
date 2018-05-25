/*********************************************************************
** Author:       Wei-Chien Hsu
** Date:         05/24/18
** Description:                   
    1. void add (std::string):
       adds a new node containing the value of the parameter to the end of the list.

    2. int positionOf (std::string):
       returns the (zero-based) position in the list for the first occurrence of the 
       parameter in the list, or -1 if that value is not in the list.

    3. bool setNodeVal(int, std::string):
       the first parameter represents a (zero-based) position in the list. 
       sets the value of the node at that position to the value of the string parameter.
       
       If the position parameter is >= the number of nodes in the list, the operation
       cannot be carried out and setNodeVal() should return false, otherwise it should
       be successful and return true. 

    4. std::vector<std::string> getAsVector():
       returns a vector with the same size, values and order as the StringList.
       
    5. a default constructor:
       initialize a new empty StringList object.

    6. a copy constructor: 
       create a completely separate duplicate of a StringList object (a deep copy)

    7. a destructor:
       delete any memory that was dynamically allocated by the StringList object.
*********************************************************************/
#include "StringList.hpp"
#include <string>
#include <vector>
#include <iostream>

/**************************************
** Struct ListNode Constructor
** Initialize the ListNode with value and 
** default pointer to nullptr
**************************************/
StringList::ListNode::ListNode(std::string val, ListNode *next = nullptr) {
  this->value = val;
  this->next = next;
}

/**************************************
** Default Constructor
** initialize a new empty StringList object.
****************************************/
StringList::StringList() {
  // Let the head pointer points to nullptr
  this->head = nullptr;
}

/**************************************
** Copy Constructor
** create a completely separate duplicate 
** of a StringList object (a deep copy)
****************************************/
StringList::StringList(const StringList &obj) {
  // If the head pointer directly points to NULL
  // The copied head pointer would point to it as well
  if(obj.head == nullptr) {
    this->head = nullptr;
  } else {
    // Initialize copied head pointer pointing to the first Node
    // The value is pointed by the object's head pointer
    this->head = new ListNode(obj.head->value);
    
    // Create a pointer points to the first node in copied List
    ListNode *copyCur = this->head;
    // Create a pointer points to the first node in the object
    ListNode *objCur = obj.head;

    // Step1: Node pointed by the copyCur will point to 
    //        the value of the next Node in the object
    //        (So wee need to make sure there is a next Node
    //         for the object)
    // Step2: move the objCur to the next Node
    // Step3: move the copyCur to the next Node
    while(objCur->next != nullptr) {
      copyCur->next = new ListNode(objCur->next->value);
      objCur = objCur->next;
      copyCur = copyCur->next;
    }
  }
}

/**************************************
** Destructor 
** delete any memory that was dynamically 
** allocated by the StringList object.
****************************************/
StringList::~StringList() {
  // Start at the the head of List
  ListNode *nodePtr = head;
  while(nodePtr != nullptr) {
    // garbage pointer keeps tracking of node to be deleted
    ListNode *garbage = nodePtr;
    nodePtr = nodePtr->next;
    // deallocates the memory used by the list
    delete garbage;
  }
}

/**************************************
** void add (std::string);
** adds a new node containing the value 
** of the parameter to the end of the list.
****************************************/
void StringList::add(std::string value) {
  // If the head pointer directly points to NULL
  // Add the Node next to the Head
  if(this->head == nullptr) {
    this->head = new ListNode(value);
  } else {
    // The List is not empty
    // Use Nodeptr to traverse the List and find the last Node
    // Add that value next to the Last Node
    ListNode *nodePtr = head;
    while(nodePtr->next != nullptr) {
      nodePtr = nodePtr->next;
    }
    // Now the nodePtr points to the Last Node
    nodePtr->next = new ListNode(value);
  }
}

/**************************************
** int positionOf (std::string):
** returns the (zero-based) position in the list for the first occurrence of the 
** parameter in the list, or -1 if that value is not in the list.
****************************************/
int StringList::positionOf(std::string target) {
  // Create a Node Pointer for traversal
  ListNode *nodePtr = head;
  // Initialize position as 0
  int pos = 0;

  // Loop through the List and find if the target is inside the list
  // If the head point to nullptr, return -1
  while(nodePtr != nullptr) {
    if(nodePtr->value == target) {
      // Return the current position
      return pos;
    }
    pos++;
    nodePtr = nodePtr->next;
  }

  // Not find the target number 
  // or the head directly points to the nullptr
  return -1;
}

/**************************************
** bool setNodeVal(int, std::string)
** sets the value of the node at that position 
** to the value of the string parameter.
****************************************/
bool StringList::setNodeVal(int pos, std::string newVal) {
  // Initialize conuter from 0
  int count = 0;
  // Create a Node Pointer for traversal
  ListNode *nodePtr = head;

  // If the head pointer points to nullptr, directly return false
  // Since the position will definitely >= 0 node
  
  if(nodePtr == nullptr) { return false; }

  // Keep Checking if the pos is out of our boundry in the list
  while(count != pos) {
    nodePtr = nodePtr->next;
    
    // When the nodePtr equal to nullptr, it means
    // the argurment of position we passed is >= the 
    // Nodes we had in the List

    if(nodePtr == nullptr) { return false; }
    count++;
  }

  // When the count == index means we met the number in that specific postion
  // Update the new Value into the current pointed Node
  nodePtr->value = newVal;
  return true;
}

/**************************************
** std::vector<std::string> getAsVector():
** returns a vector with the same size, 
** values and order as the StringList.
****************************************/
std::vector<std::string> StringList::getAsVector() {
  // Initialize a new vector included pointer to the string data type
  std::vector<std::string> vec;
  // Create a Node Pointer for traversal
  ListNode *nodePtr = head;

  // While the node pointer didn't mean the last Node
  // Keep pushing the value pointed into the vector
  while(nodePtr != nullptr) {
    vec.push_back(nodePtr->value);
    nodePtr = nodePtr->next;
  }
  // If the head points to the null
  // directly return an empty vector
  return vec;
}

// For Testing
/**************************************
** displayList():
** Traversal(display) a sequence of all values
** currently stored in the list.
****************************************/
void StringList::displayList() const {
  ListNode *nodePtr = head; // Start at head of list
  while(nodePtr != nullptr) {
    std::cout << nodePtr->value << "  ";
    nodePtr = nodePtr->next;
  }
}