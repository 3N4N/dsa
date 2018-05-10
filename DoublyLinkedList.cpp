#include <iostream>

template <class T>
class Node {
public:
  Node(T value) {
    this->value = value;
    prev = NULL;
    next = NULL;
  }
  virtual ~Node() {

  }
  void setValue(Node<T> * value) {
    this->value = value;
  }
  void setPrev(Node<T> * prev) {
    this->prev = prev;
  }
  void setNext(Node<T> * next) {
    this->next = next;
  }
  T getValue() {
    return value;
  }
  Node<T> * getPrev() {
    return prev;
  }
  Node<T> * getNext() {
    return next;
  }

private:
  T value;
  Node<T> * prev;
  Node<T> * next;
};

template <class T>
class DoublyLinkedList
{
public:
  DoublyLinkedList ();         // create a singly linked list
  DoublyLinkedList (T);        // create a singly linked list and add item
  virtual ~DoublyLinkedList(); // delete list and release memory
  void add(T);                 // add item at the last
  void insertFirst(T);         // add item at the beginning
  void remove(T);              // remove first occurrence of item
  void removeAllOf(T);         // remove all occurrence of item
  void printList();            // print the items of the list

private:
  Node<T> * head;
  Node<T> * tail;
};

template <class T>
DoublyLinkedList<T>::DoublyLinkedList () {
  head = NULL;
  tail = NULL;
}

template <class T>
DoublyLinkedList<T>::DoublyLinkedList (T value) {
  head = new Node<T>(value);
  tail = head;
}

template <class T>
DoublyLinkedList<T>::~DoublyLinkedList() { }

template <class T>
void DoublyLinkedList<T>::add(T value) {
  Node<T> * newNode = new Node<T>(value);
  if (tail==NULL && head==NULL) {
    head = newNode;
    tail = head;
    return ;
  }

  tail->setNext(newNode);
  newNode->setPrev(tail);
  tail = newNode;
}

template <class T>
void DoublyLinkedList<T>::insertFirst(T value) {
  Node<T> * newNode = new Node<T>(value);
  if (tail==NULL && head==NULL) {
    head = newNode;
    tail = head;
  }

  head->setPrev(newNode);
  newNode->setNext(head);
  head = newNode;
}

template <class T>
void DoublyLinkedList<T>::remove(T value) {
  if (head==NULL && tail==NULL) return ;
  if (head->getValue() == value) {
    if (head==tail) {
      head = tail = NULL;
    } else {
      head = head->getNext();
      head->setPrev(NULL);
    }
    return ;
  }

  Node<T> * currentNode = head;
  while (currentNode->getValue()!=value && currentNode->getNext()!=NULL)
    currentNode = currentNode->getNext();
  if (currentNode->getValue() == value) {
    if (currentNode == tail) {
      tail = tail->getPrev();
      tail->setNext(NULL);
    } else {
      currentNode->getPrev()->setNext(currentNode->getNext());
      currentNode->getNext()->setPrev(currentNode->getPrev());
    }
  }
}

template <class T>
void DoublyLinkedList<T>::removeAllOf(T value) {
  if (head==NULL && tail==NULL) return ;

  while (head->getValue() == value) {
    if (head==tail) {
      head = tail = NULL;
      return ;
    }
    else {
      head = head->getNext();
      head->setPrev(NULL);
    }
  }
  Node<T> * currentNode = head;
  while (currentNode->getNext()!=NULL) {
    currentNode = currentNode->getNext();
    if (currentNode->getValue() == value) {
      currentNode->getPrev()->setNext(currentNode->getNext());
      currentNode = currentNode->getPrev();
      if (currentNode->getNext() != NULL)
        currentNode->getNext()->setPrev(currentNode);
      else tail=currentNode;
    }
  }
}

template <class T>
void DoublyLinkedList<T>::printList() {
  if (head==NULL) {
    std::cout << "List is empty" << std::endl;
    return ;
  }
  Node<T> * currentNode = head;
  std::cout << currentNode->getValue() << " ";
  while (currentNode->getNext() != NULL) {
    currentNode = currentNode->getNext();
    std::cout << currentNode->getValue() << " ";
  }
  std::cout << std::endl;
}
