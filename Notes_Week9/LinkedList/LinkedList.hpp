#include <iostream>

template<class T>
class LinkedList {
  protected:
    struct ListNode {
      T value;
      ListNode *next;
      ListNode(T value, ListNode *next = nullptr) {
        this->value = value;
        this->next = next;
      } 
    };
    ListNode *head;
  public:
    LinkedList() { head = nullptr; }
    ~LinkedList();
    void add(T value);
    void remove(T value);
    void displayList() const;
};

/***************
 * Add Node
****************/
template<class T>
void LinkedList<T>::add(T value) {

  if(head == nullptr) {
    head = new ListNode(value);
  } else {
    ListNode *nodePtr = head;
    while(nodePtr->next != nullptr) {
      nodePtr = nodePtr->next;
    }
    nodePtr->next = new ListNode(value);
  }
}

/***************
 * Remove the Node
****************/
template<class T>
void LinkedList<T>::remove(T target) {
  // If the List is empty
  if(this->head == nullptr) { return; }

  ListNode *nodePtr = head;
  ListNode *previousNode;
  // If the First Node is the target
  if(this->head->value == target) {
    this->head = this->head->next;
    delete nodePtr;
  } else {
    // Traverse the List to find the target
    while(nodePtr!= nullptr && nodePtr->value != target) {
      previousNode = nodePtr;
      nodePtr = nodePtr->next;
    }
    // head -> 1 -> 2 -> 3 target = 2
    //         p    n

    if(nodePtr != nullptr) {
      previousNode->next = nodePtr->next;
      delete nodePtr;
    }
  }
}

/***************
 * Display
****************/
template<class T>
void LinkedList<T>::displayList() const {
  ListNode *nodePtr = head;
  while(nodePtr != nullptr) {
    std::cout << nodePtr->value << "  ";
    nodePtr = nodePtr->next;
  }
  std::cout << std::endl;
}

/***************
 * Destructor
****************/
template<class T>
LinkedList<T>::~LinkedList() {
  ListNode *nodePtr = head;
  while(nodePtr != nullptr) {
    ListNode *garbage;
    garbage = nodePtr;
    nodePtr = nodePtr->next;
    delete garbage;
  }
}

