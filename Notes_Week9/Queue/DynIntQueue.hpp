#include <iostream>

class DynIntQueue {
  protected:
    struct QueueNode {
      int value;
      QueueNode *next;
      QueueNode(int value, QueueNode *next = nullptr) {
        this->value = value;
        this->next = next;
      }
    };
    QueueNode *front;
    QueueNode *rear;
  public:
    DynIntQueue();
    ~DynIntQueue();
    void enqueue(int);
    int dequeue();
    bool isEmpty();
    void clear();
};

DynIntQueue::DynIntQueue() {
  this->front = nullptr;
  this->rear = nullptr;
}

DynIntQueue::~DynIntQueue() {
  QueueNode *garbage = front;
  while(garbage != nullptr) {
    front = front->next;
    garbage->next = nullptr;
    delete garbage;
    garbage = front;
  }
}

void DynIntQueue::enqueue(int num) {
  if(isEmpty()) {
    this->front = new QueueNode(num);
    this->rear = this->front;
  } else {
    // Connect the last Node to a new one 
    // Update the rear pointer points to the latest one
    rear->next = new QueueNode(num);
    this->rear = this->rear->next;
  }
}

int DynIntQueue::dequeue() {
  QueueNode *prev;
  if(isEmpty()){
    std::cout << "The Queue is Empty. \n";
    exit(1);
  } else {
    prev = this->front;
    int num = this->front->value;
    this->front = this->front->next;
    delete prev;
    return num;
  }
}

bool DynIntQueue::isEmpty() {
  return this->front == nullptr;
}

void DynIntQueue::clear() {
  while(!isEmpty()) {
    dequeue();
  }
}