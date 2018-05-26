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