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