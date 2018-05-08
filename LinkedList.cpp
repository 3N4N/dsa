#include <iostream>

template <class T>
class Node
{
public:
  Node (T value) {
    this->value = value;
    next = NULL;
  }
  virtual ~Node () {
  }
  void setNext(Node<T> * next) {
    this->next = next;
  }
  void setValue(T value) {
    this-> value = value;
  }
  Node<T> * getNext() {
    return next;
  }
  T getValue() {
    return value;
  }

private:
  T value;
  Node<T> * next;
};

template <class T>
class LinkedList
{
public:
  LinkedList (T);          // create a singly linked list
  virtual ~LinkedList ();  // delete list and release memory
  void add(T);             // add item at the last
  void insertFirst(T);     // add item at the beginning
  void remove(T);          // remove first occurrence of item
  void removeAllOf(T);     // remove all occurrence of item
  void printList();        // print the items of the list

private:
  Node<T> * root;
};

template <class T>
LinkedList<T>::LinkedList(T value) {
  root = new Node<T>(value);
}

template <class T>
LinkedList<T>::~LinkedList() {
}

template <class T>
void LinkedList<T>::add(T value) {
  Node<T> * currentNode = root;
  Node<T> * tmpNode = new Node<T>(value);

  while (currentNode->getNext() != NULL)
    currentNode = currentNode->getNext();
  currentNode->setNext(tmpNode);
}

template <class T>
void LinkedList<T>::insertFirst(T value) {
  Node<T> * tmpNode = new Node<T>(value);
  tmpNode->setNext(root);
  root = tmpNode;
}

template <class T>
void LinkedList<T>::remove(T value) {
  if (root->getValue() == value) {
    root = root->getNext();
    return ;
  }
  Node<T> * currentNode = root;
  Node<T> * previousNode = NULL;
  while ( (currentNode->getValue() != value) && (currentNode->getNext() != NULL) ) {
    previousNode = currentNode;
    currentNode = currentNode->getNext();
  }

  if (currentNode->getValue() == value) {
    currentNode = currentNode->getNext();
    previousNode->setNext(currentNode);
  }
}

template <class T>
void LinkedList<T>::removeAllOf(T value) {
  if (root->getValue() == value) {
    root = root->getNext();
  }

  Node<T> * currentNode = root;
  Node<T> * previousNode = NULL;

  bool flag=true;
  while (flag) {
  while ( (currentNode->getValue() != value) && (currentNode->getNext() != NULL) ) {
    previousNode = currentNode;
    currentNode = currentNode->getNext();
  }

  if (currentNode->getValue() == value) {
    currentNode = currentNode->getNext();
    previousNode->setNext(currentNode);
  } else if (currentNode->getNext() == NULL)
    return ;
  }
}

template <class T>
void LinkedList<T>::printList() {
  int i=1;
  Node<T> * currentNode = root;
  std::cout << i++ << ": " << currentNode->getValue() << std::endl;
  while (currentNode->getNext() != NULL) {
    currentNode = currentNode->getNext();
    std::cout << i++ << ": " << currentNode->getValue() << std::endl;
  }
}
