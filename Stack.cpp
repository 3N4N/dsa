#include <iostream>

template <class T>
class Stack
{
public:
  Stack (int);
  void push(T);
  void pop();
  T peek();
  int size() { return top+1; }

private:
  T * arr;
  int capacity;
  int top;
};

template <class T>
Stack<T>::Stack(int capacity) {
  this->capacity = capacity;
  top = -1;
  arr = new T[capacity];
}

template <class T>
void Stack<T>::push(T value) {
  if (size() >= capacity) {
    std::cout << "Stack is full." << std::endl;
    return ;
  }

  top++;
  arr[top] = value;
}

template <class T>
void Stack<T>::pop() {
  if (size() <= 0) {
    std::cout << "Stack is empty." << std::endl;
    return ;
  }
  top--;
}

template <class T>
T Stack<T>::peek() {
  return arr[top];
}
