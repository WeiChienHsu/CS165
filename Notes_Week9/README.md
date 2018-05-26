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

# Stacks

Last In First Out. Like an array or a lnked list, a stack is a data structure that holds a sequence of elements. When a program retrieves elements from a stack, the last element inserted into the stack is the first one retrieved.

## Application of Stacks
Stacks are useful data structures for algorithm that work first with the last saved element of a series.
Computer systems use stacks while executing programs. When a function is called, the computer stores the program's return address, the parameters to the function and the function's local variables on a stack. When the function returns, the local variables, parameters, and return address are removed form the stack.

- Static Stacks: have a fix size and are implemented as arrays.
- Dynamic Stacks: stack grows in size as needed and are implementted as linkedlist.

### Operation
- push: casue the value to be stored
- pop: retrieves a value from the stack

***
## Static Stack

### Member Variable
- statckArray
- capacity
- top

### Member funciton 
- Constructor
- push 
- pop
- isEmpty

### Exception
- OverFlow: push function announces the occurrence of an overflow exception
- UnderFlow: pop funciton executes the statement


```c++
#include <iostream>

class IntStack {
  protected:
    int *stactPtr;
    int capacity;
    int top;
  public:
    IntStack(int capacity);
    ~IntStack();
    void push(int value);
    int pop();
    bool isEmpty() const; 

    class Overflow {};
    class Underflow {};
};

IntStack::IntStack(int capacity) {
  this->stactPtr = new int[capacity];
  this->capacity = capacity;
  this->top = 0;
}

IntStack::~IntStack() {
  delete[] this->stactPtr;
}

void IntStack::push(int value) {
  if(top == capacity) throw IntStack::Overflow();
  stactPtr[top] = value;
  top++;
}

bool IntStack::isEmpty() const {
  return top == 0;
}

int IntStack::pop() {
  if(isEmpty()) throw IntStack::Underflow();
  top--;
  return stactPtr[top];
}
```

***
## Dynamic Stack
A dynamic stack is built on a linked list instead of on an array. A stack based on a linked list offeres two advantages over a stack based on an array.

- There is no need to specify the starting size of the stack.(Simply start at empty linked list, then expands by one node each time a value is pushed)
- Never be full! as long as the systemn has enough free moemory.

### Implementaion
The StackNode class is the data type of each node in the linked list. Because it is easy to add and remove items at the beginning of the list, we make the beginning of the linked list the top of the stack and use a pointer top to point to the first node in the list.

The push funtion creates a new node whose value is the number to be push ed on the stack and whose successor pointer is the node that is currently the top of the stack and then make the newly created node the new top of the stack.

```c++
top = new StackNode(num, top)
```

```
top -> 1
push(2, top)
top -> 2 -> 1

top -> null
push (2, top)
top -> 2 -> null
```
- DynIntStack
```c++
#include <iostream>


class DynIntStack
{
protected:
  
  struct StackNode
  {
    int value;
    StackNode *next;
    StackNode(int value, StackNode *next = nullptr) {
      this->value = value;
      this->next = next;
    }
  };
  StackNode *top;

public:
  DynIntStack() { top = nullptr; }
  ~DynIntStack();
  void push(int);
  int pop();
  bool isEmpty() const;

  class Underflow { };
};

DynIntStack::~DynIntStack()
{
  StackNode *garbage = top;
  while(garbage != nullptr) {
    top = top->next;
    garbage->next = nullptr;
    delete garbage;
    garbage = top;
  }
}

void DynIntStack::push(int value)
{
  top = new StackNode(value, top);
}

int DynIntStack::pop()
{
  StackNode *temp;
  int num;

  if(DynIntStack::isEmpty()) { throw Underflow(); }
  else {
    num = top->value;
    temp = top;
    top = top->next;
    delete temp;
  }
  return num;
}

bool DynIntStack::isEmpty() const{
  return this->top == nullptr;
}
```
- Main Function
```c++
  DynIntStack dynStack;
  dynStack.push(10);
  std::cout << dynStack.pop() << std::endl;
  std::cout << dynStack.isEmpty() << std::endl;
  
  try {
    std::cout << dynStack.pop() << std::endl;
  } catch(DynIntStack::Underflow) {
     std::cout << "Stack is Empty!" << std::endl;
  }
```

***
## STL Stack Container

The purpose of the new interface is to make it more convenient to use the class for specialized tasks. Because the stack container is used to adapt the list, vector, and deque continers, it is often referred to as a container adapter.

```c++
stack<int, vector<int>> //Vector stack
stack<int, list<int>> // List Stack
stack<int> iStack // Deque stack (the default)
```


### Mumber Function
- empty()
- pop(): removes tje element at the top of the stack (The pop funciton in the stack does not retrieve the value from the top of the stack; it only removes it. To retrieve the value, you must call the top function first)
- push()
- size()
- top(): Return a reference to the element at the top of the stack.


```c++
#include <iostream>
#include <stack>

int main() {
  std::stack<double> dStack;

  for(double x = 2; x < 9; x++) {
    std::cout << "Pushing " << x << std::endl;
    dStack.push(x);
  }

  std::cout << "The size of the stack is: ";
  std::cout << dStack.size() << std::endl;

  while(!dStack.empty()) {
    std::cout << dStack.top() << std::endl;
    dStack.pop();
  }
  return 0;
}
```
***
## Assignment 9
- strtok()初次使用时，需要传入str，将str的首个字符位置作为查找的起始位置，并返回不包含dilimiters定义字符的子串；后续使用传入NULL，并使用上一次查找到子串的尾部位置的下一个位置作为查找起始位置，继续查找。
```c++
char *token = std::strtok(userEq, " ");
token = std::strtok(nullptr, " ");
```

```c++
  std::string str = "25 12 7 - 2 * /";
  char* chr = strdup(str.c_str());  // {[2],[5],[ ],...}

  char* token = std::strtok(chr, " "); // token points to "25"
  std::cout << token << std::endl;
  token = std::strtok(nullptr, " "); // Give a NULL and seperate by " ", token points to "12"
  std::cout << token << std::endl;
```

- atof()将字符串转为double类型
```c++
double number = atpf(token)
```

***
# Queue
First In First Out. Important in multiuser/multitasking environment where several users or tasks may be requesting the same resource simultaneously. Printing, for example, is controlled by a queue because only one document may be printed at a time.

Communications sotware also uses queues to hold information received over networks and dial-up connections. Sometimes information is transmitted to a system faster than it can be processed, so it is placed in a queue when it is received.

## Queue Operations
A queue has a front and a rear like a checkout line in a grocery store. When an element is added to a queue, it is added to the rear. When an element is removed from a queue, it is removed from the front.


```c++
#include <iostream>
#include <cstdlib>

class IntQueue {
  private:
    int* ptr;
    int queueSize;
    int front;
    int rear;
    int numItems;
  public:
    IntQueue(int);
    ~IntQueue();
    void enqueue(int);
    int dequeue();
    bool isEmpty() const;
    bool isFull() const;
    void clear();
};

IntQueue::IntQueue(int s) {
  this->ptr = new int[s];
  this->queueSize = s;
  this->front = -1;
  this->rear = -1;
  this->numItems = 0;
}

IntQueue::~IntQueue() {
  delete[] ptr;
}

void IntQueue::enqueue(int num) {
  if(isFull()) {
    std::cout << "The queue is full \n";
    exit(1);
  } else {
    // Calculate the new rear position
    this->rear = (rear + 1) % this->queueSize;
    // Insert new item
    ptr[rear] = num;
    // Update item count
    this->numItems++;
  }
}

int IntQueue::dequeue() {
  if(isEmpty()) {
    std::cout << "The queue is Empty \n";
    exit(1);
  } else {
    int num = 0;
    // Move front
    this->front = (front + 1) % this->queueSize;
    // Retrieve the front item
    num = ptr[front];
    // Return num
    return num;
  }
}

bool IntQueue::isEmpty() const {
  return this->numItems == 0;
}

bool IntQueue::isFull() const {
  return this->numItems == this->queueSize;
}

void IntQueue::clear() {
  this->front = -1;
  this->rear = -1;
  this->numItems = 0;
}
```