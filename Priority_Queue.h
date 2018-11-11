#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H


#include <iostream>

#define NULL_VALUE -99999

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
    void setPriority(int priority) {
        this->priority = priority;
    }
    Node<T> * getNext() {
        return next;
    }
    T getValue() {
        return value;
    }
    int getPriority() {
        return priority;
    }

private:
    T value;
    int priority;
    Node<T> * next;
};

template<class T>
class Priority_Queue
{
private:
    Node<T> *front;
public:
    Priority_Queue() {
        front = NULL;
    }
    void enqueue(T item, int priority);
    T dequeue();
    bool isEmpty();
    bool isInQueue(T item);
};

template <class T>
void Priority_Queue<T>::enqueue(T item, int priority) {
    Node<T> *tmp;
    Node<T> *q;
    tmp = new Node<T>(item);
    tmp->setPriority(priority);
    if (front == NULL || priority < front->getPriority()) {
        tmp->setNext(front);
        front = tmp;
    }
    else {
        q = front;
        while (q->getNext() != NULL && q->getNext()->getPriority() <= priority)
            q=q->getNext();
        tmp->setNext(q->getNext());
        q->setNext(tmp);
    }
}

template <class T>
T Priority_Queue<T>::dequeue() {
    Node<T> *tmp;
    T ret;
    if(front == NULL)
        std::cout << "Queue Underflow\n";
    else
    {
        tmp = front;
        front = front->getNext();
        ret = tmp->getValue();
        free(tmp);
    }
    return ret;
}

template <class T>
bool Priority_Queue<T>::isEmpty() {
    if (front == NULL) return true;
    else return false;
}

template <class T>
bool Priority_Queue<T>::isInQueue(T item) {
    if (front->getValue() == item)
        return true;
    Node<T> *tmp = front;
    while (tmp->getNext()!=NULL) {
        tmp = tmp->getNext();
        if (tmp->getValue() == item) return true;
    }
    return false;
}

#endif          // PRIORITY_QUEUE_H
