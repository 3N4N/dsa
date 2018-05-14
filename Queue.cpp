#include <iostream>
#include <cmath>

#define NULL_VALUE -99999

template <class T>
class Queue
{
public:
  Queue (int);      // create queue with given capacity
  ~Queue();
  void enqueue(T);  // push item at the last
  void dequeue();  // pop item from the beginning
  T first();        // return item at the beginning
  T last();         // return item at the end
  int size();       // return the size

private:
  T * arr;
  int capacity;
  int head;
  int tail;
  int length;
};

template <class T>
Queue<T>::Queue(int capacity) {
  this->capacity = capacity;
  head = 0;
  tail = -1;
  length = 0;
  arr = new T[capacity];
}

template <class T>
Queue<T>::~Queue() {
  if (arr) delete[] arr;
  arr = NULL;
}

template <class T>
void Queue<T>::enqueue(T value) {
  if (size() >= capacity) {
    std::cout << "Queue is full." << std::endl;
    return ;
  }

  tail = ( tail + 1 ) % capacity;
  arr[tail] = value;
  length++;
}

template <class T>
void Queue<T>::dequeue() {
  if (size() <= 0) {
    std::cout << "Queue is empty." << std::endl;
    return ;
  }

  head = ( head + 1 ) % capacity;
  length--;
}

template <class T>
T Queue<T>::first() {
  if (size() <= 0) return NULL_VALUE;
  return arr[head];
}

template <class T>
T Queue<T>::last() {
  if (size() <= 0) return NULL_VALUE;
  return arr[tail];
}

template <class T>
int Queue<T>::size() {
  return length;
}
