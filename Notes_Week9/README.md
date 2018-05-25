# Abstract Data Types - LinkedList, Stacks, Queue

## Chapter 17

To insert or remove a value at the beginning or middle of a vector is O(n).  For a linked list, the same operations are O(1).
Linked lists can be tricky because they involve lots of pointer manipulation, and you have to keep careful track of what is pointing to what at different steps along the way.  Pictures (like the ones shown in the text) can be very helpful in keeping mental track.

## Chapter 18
Stacks and queues are simply more specialized versions of linked lists.  
They also serve as a useful case study in the design of abstract data types.

***

# Linked Lists

A linked list is a series of connected nodes, where each node is a data structure. The nodes of a linked list are usually dynamically allocated, used, and then deleted, allowing the linked list to grow or shrink in size as the program runs.

If new information needs to be added to a linked list, the program simply allocates another node and inserts it into the series. If a particular piece of informaion needs to be removed from the linked list, the program deletes the node containing that information.

### Advantage
The programmer doesn't need to know how many nodes will be in the list. 
They are simply created in memory as they are needed.
Have over vectors the speed at which a node may be inserted into or deleted from the list.

### Structure of Linked Lists
Each node in a linked list contains one or more members that hold data and Each node contains a successor pointer that points that points to the next node in the list.

The first node of a nonempty linked list is called the head of the list. To access the nodes in a linked list, you need to have a pointer to the head of the list.

Beginning with the head, you can access the rest of the nodes in the list by following the successor pointers stored in each node. The successor pointer in the last node is set to nullptr to indicate the end of the list.

Because the pointer to the head of the lust is used to locate the head of the list, we can think of it as representing the list head. The same pointer can also be used to licate the entire list by starting at the head and following the successor pointers, so it is also natural to think of it sas representing the entire list.

### C++ Representaiton of Linked Lists
- Address of head Pointer(0x7ffee3f047d0) 
- Address of head Pointer point to(0x7ffd22c027f0) is Equal to 'Address of First Value'(0x7ffd22c027f0)
- The pointer in the First Node is loacted nearby the Value(0x7ffd22c027f8)
- The pointer in the First Node point to(0x7f9cd5c02800) is Equal to 'Address of Second Value'(0x7f9cd5c02800)
- First Node and Second Node are far away to each other (Not sequencial)

```c++
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
```

***

### Using Constructors to Initialize Nodes
Recalling that  C++ structures can have constructors. It is often convenient to provide the structures that define the type for a list node with one or more constructors, to allow nodes to be initialized as soon as they are created.

```c++
struct ListNode {
  double value;
  ListNode *next;
  ListNode(double val, ListNode *next = nullptr) {
    this->value = val;
    this->next = next;
  }
};
```
With this declaration, a node can be created in two different wyas:
- By specifying just its value part and letting the succesor pointer default to nullptr
- By specifying both the value part and a pointer to the node that is to follow this one in the list

```c++
ListNode *secondPtr = new ListNode(13.0) //Default points to Nullptr
ListNode *head = new ListNode(10.0, secondPtr);
```

We can actually dispense with the second pointer and write the above code as:
```c++
ListNode *head = new ListNode(13.0);
head = new ListNode(10.0, head)
```
First the old value of head is used in the constructor, and then the address returned from the new operatpr is assignmed to head, becoming its new value.

```
head -> | 13 |  | -> null
head -> | 10 |  | -> | 13 |  | -> null 
```

### Example
```c++
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

  cout << "First Item: " << head->value << endl;
  cout << "Second Item " << head->next->value << endl;
  cout << "Third Item " << head->next->next->value << endl;
  return 0;
}
```
```
First Item: 5
Second Item 10
Third Item 12.5
```


### Building a List
Using the constructor version of LustNode is very easy to create a list by reading values from a file and adding each newly read value to the beginning of the list of values already accumulated.

```c++
ListNode *numberList = nullptr
double number;
while(numberFile >> number) {
  //Create a node to hold this number
  numberList = new ListNode(number, numberList)
}
```

### Traversing a List

```c++
ListNode *ptr = numberList;
while(ptr!= nullptr) {
  cout << ptr->value << " ";
  ptr = ptr->next;
}
```
***
## Linked List Operations
The basic linked list operations are adding an element to a list, removing an element from the list, traversing the list, and destroying the list.

### Add an Element to the List
- If head point to the NULL means it's the first element we add into the List
- If there are some nodes in the list, used another node pointer to point to the last node (which is nodePtr->next != null), then we add an element to the next of current node pointed by the nodePtr.

```c++
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
```

### Traversing the list

```c++
void NumberList::displayList() const {
  ListNode *nodePtr = head; // Start at head of list
  while(nodePtr != null) {
    cout << nodePtr->value << "  ";
    nodePtr = nodePtr->next;
  }
}
```

### Destroying 
It does this by stepping through the lust, deleting one node at a time. 
A pointer nodePtr starts a t the beginning (head) of the list and steps through the list one node at a time. A second pointer, garbage, follows in nodePtr's wake and is used to delete each node as soon as nodePtr has passed on the node's successor.

```c++
NumberList::~NumberList() {
  ListNode *nodePtr = head; // Start at head of list
  while(nodePtr != nullptr) {
    // garbage keeps track of node to be delete
    ListNode *garbage = nodePtr;
    nodePtr = nodePtr->next;
    delete garbage;
  }
}
```

### Remove
Remove an element from a linked list requires a number of steps
1. Locating the node containing the element to be removed
2. Unhooking the node from the list
3. Deleting the memory allocated to the node

The remove member function uses a pointer nodePtr to search for a node containing the value number that is to be removed.

During this process, a second pointer prevousNodePtr trails behind nodePtr, always pointing to the node preceding the one pointed to byu nodePtr.

When nodePtr points to the node to be deleted, previousNodePtr->next is set to nodePtr->next. 

This Casue the successor pointers in the list to bypass the node containing number, allowing its memory to be freed using delete.

## Copy Constructor

When you copy a container such as a linked list, you probably want a deep copy, so new nodes need to be created and only the data copied over. The next and prior pointers in the nodes of the new list should refer to new nodes you create specifically for that list and not the nodes from the original list. These new nodes would have copies of the corresponding data from the original list, so that the new list can be considered a by value, or deep copy.

- Shallow Copy
```
Orininal      New
List Head   List Head
    |       /
  Node  ---
    |
  Node
    |
  null
```

- Deep Copy
```
Orininal      New
List Head   List Head
    |         |
  Node       Node
    |         |
  Node       Node
    |         |
  null       null
```



```c++
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
```

***
## Linked List Template

```c++
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

```

```c++
#include "LinkedList.hpp"
#include <string>
#include <iostream>

int main() {
  LinkedList<int> integerList;
  integerList.add(10);
  integerList.add(20);
  integerList.displayList();

  LinkedList<std::string> stringList;
  stringList.add("Abc");
  stringList.remove("Abc");
  stringList.add("CCC");
  stringList.displayList();
  return 0;
}
```

***