#ifndef QUEUE_H
#define QUEUE_H


#include <iostream>
#include <cmath>


template <class T>
class Queue
{
public:
    Queue (int);      // create queue with given capacity
    ~Queue();
    void enqueue(T);  // push item at the last
    void dequeue();   // pop item from the beginning
    T first() const;  // return item at the beginning
    T last() const;   // return item at the end
    int size() const; // return the size

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
T Queue<T>::first() const {
    return arr[head];
}

template <class T>
T Queue<T>::last() const {
    return arr[tail];
}

template <class T>
int Queue<T>::size() const {
    return length;
}

#endif          // QUEUE_H
