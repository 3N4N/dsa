#include <iostream>
#include <cmath>

#define NULL_VALUE -99999

template <class T>
class Queue
{
public:
  Queue (int);
  void enqueue(T);
  void dequeue(T);
  T first();
  T last();
  int size();

private:
  T * arr;
  int capacity;
  int head;
  int tail;
};

template <class T>
Queue<T>::Queue(int capacity) {
  this->capacity = capacity;
  head = 0;
  tail = -1;
}

template <class T>
void Queue<T>::enqueue(T value) {
  if (size() >= capacity) {
    std::cout << "Queue is full." << std::endl;
    return ;
  }

  tail = ( tail + 1 ) % capacity;
  arr[tail] = value;
}

template <class T>
void Queue<T>::dequeue(T value) {
  if (size() <= 0) {
    std::cout << "Queue is empty." << std::endl;
    return ;
  }

  head = ( head + 1 ) % capacity;
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
  if (tail==-1) return 0;
  return std::abs( head - tail ) + 1;
}
