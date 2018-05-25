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
