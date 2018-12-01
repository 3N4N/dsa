#ifndef LINKEDLIST_H
#define LINKEDLIST_H


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
    Node<T> * getNext() const {
        return next;
    }
    T getValue() const {
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
    LinkedList ();                             // create a linked list
    virtual ~LinkedList ();                    // delete list and release memory
    Node<T>* getRoot() const { return root; }  // get the head pointer
    int size() const { return len; }           // return size of the list
    void add(T value);                         // add item at the last
    void add(LinkedList list);                 // add a linked list
    void insertFirst(T value);                 // add item at the beginning
    void remove(T value);                      // remove first occurrence of item
    void removeAllOf(T value);                 // remove all occurrence of item
    void clear();                              // remove all elements
    template<class P>
        friend std::ostream& operator<<(std::ostream& os, const LinkedList<P>& obj);

private:
    Node<T> * root;
    int len;
};

template <class T>
LinkedList<T>::LinkedList() {
    root = NULL;
    len = 0;
}

template <class T>
LinkedList<T>::~LinkedList() {
    root = NULL;
    len = 0;
}

template <class T>
void LinkedList<T>::add(T value) {
    Node<T> * tmpNode = new Node<T>(value);
    if (root==NULL) {
        root = tmpNode;
        len++;
        return ;
    }

    Node<T> * currentNode = root;
    while (currentNode->getNext() != NULL)
        currentNode = currentNode->getNext();
    currentNode->setNext(tmpNode);

    len++;
}

template <class T>
void LinkedList<T>::add(LinkedList list) {
    Node<T> *listRoot = list.getRoot();
    if(root == NULL) {
        root = listRoot;
        len = list.size();
        return;
    }
    Node<T> *currentNode = root;
    while(currentNode->getNext()!=NULL)
        currentNode = currentNode->getNext();
    currentNode->setNext(listRoot);

    len += list.size();
}

template <class T>
void LinkedList<T>::insertFirst(T value) {
    Node<T> * tmpNode = new Node<T>(value);
    tmpNode->setNext(root);
    root = tmpNode;

    len++;
}

template <class T>
void LinkedList<T>::remove(T value) {
    if (root==NULL) return ;
    if (root->getValue() == value) {
        root = root->getNext();
        len--;
        return ;
    }
    Node<T> * currentNode = root;
    Node<T> * previousNode = NULL;
    while (currentNode->getValue() != value && currentNode->getNext() != NULL) {
        previousNode = currentNode;
        currentNode = currentNode->getNext();
    }

    if (currentNode->getValue() == value) {
        currentNode = currentNode->getNext();
        previousNode->setNext(currentNode);
        len--;
    }
}

template <class T>
void LinkedList<T>::removeAllOf(T value) {
    if (root==NULL) return ;
    if (root->getNext()==NULL) {
        remove(value);
        return ;
    }
    // Remove all the nodes with matching value from the beginning
    while (root!=NULL && root->getValue() == value) {
        root = root->getNext();
        len--;
    }
    if(root==NULL) return;

    Node<T> * currentNode = root;
    Node<T> * previousNode = NULL;

    // traverse list and remove matching nodes until hit end
    while (currentNode->getNext()!=NULL) {
        previousNode = currentNode;
        currentNode = currentNode->getNext();

        if (currentNode->getValue()==value) {
            previousNode->setNext(currentNode->getNext());
            currentNode = previousNode;
            len--;
        }
    }
}

template <class T>
void LinkedList<T>::clear() {
    root = NULL;
    len = 0;
}

template<class P>
std::ostream& operator<<(std::ostream& os, const LinkedList<P>& obj) {
    Node<P> *root = obj.getRoot();
    if (root==NULL) {
        os << "List is empty" << "\n";
        return os;
    }
    Node<P> * currentNode = root;
    os << currentNode->getValue() << " ";
    while (currentNode->getNext() != NULL) {
        currentNode = currentNode->getNext();
        os << currentNode->getValue() << " ";
    }
    os << "\n";
    return os;
}

#endif          // LINKEDLIST_H
