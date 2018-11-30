#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H


#include <iostream>
#include "ArrayList.h"


template<class T>
class MinHeap {
private:
    ArrayList<T> heap;
    ArrayList<int> priority;
    int left(int parent);                     // return index of left child
    int right(int parent);                    // return index of right child
    int parent(int child);                    // return index of parent
    void increaseKey(int i, int v);
    void decreaseKey(int i, int v);

public:
    MinHeap() { }
    void insert(T element, int p);           // insert element into heap
    void deleteMin();                        // delete minimum element
    T extractMin();                          // extract minimum element
    int size();                              // return heap size
    void sift_down(int index);               // maintain heap structure
    void sift_up(int index);                 // maintain heap structure
    void buildHeap();
    void updateKey(int i, int v);
    void displayHeap();
};

template<class T>
int MinHeap<T>::size() {
    return heap.size();
}

template<class T>
int MinHeap<T>::left(int parent) {
    int l = 2 * parent + 1;
    return l;
}

template<class T>
int MinHeap<T>::right(int parent) {
    int r = 2 * parent + 2;
    return r;
}

template<class T>
int MinHeap<T>::parent(int child) {
    int p = (child - 1)/2;
    return p;
}

template<class T>
void MinHeap<T>::insert(T element, int p) {
    heap.add(element);
    priority.add(p);
}

template<class T>
void MinHeap<T>::deleteMin() {
    heap.assign(0, heap.at(heap.size()-1));
    priority.assign(0, priority.at(priority.size()-1));
    heap.removeAt(heap.size() - 1);
    priority.removeAt(priority.size() - 1);
    sift_down(0);
}

template<class T>
T MinHeap<T>::extractMin() {
    return heap.at(0);
}

template<class T>
void MinHeap<T>::increaseKey(int i, int v) {
    priority.assign(i, v);
    sift_down(i);
}

template<class T>
void MinHeap<T>::decreaseKey(int i, int v) {
    priority.assign(i, v);
    sift_up(i);
}

template<class T>
void MinHeap<T>::updateKey(int i, int v) {
    if (v < priority.at(i))
        decreaseKey(i, v);
    else if (v > priority.at(i))
        increaseKey(i, v);
}

template<class T>
void MinHeap<T>::sift_down(int i) {
    int n = heap.size();
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int least = i;
    if (l < n && priority.at(l) < priority.at(least))
        least = l;
    if (r < n && priority.at(r) < priority.at(least))
        least = r;
    if (least != i) {
        int tmp = priority.at(i);
        priority.assign(i, priority.at(least));
        priority.assign(least, tmp);
        T tmpHeap = heap.at(i);
        heap.assign(i, heap.at(least));
        heap.assign(least, tmpHeap);
        sift_down(least);
    }
}

template<class T>
void MinHeap<T>::sift_up(int i) {
    int n = heap.size();
    int p = parent(i);
    if( priority.at(i) < priority.at(p) ) {
        int tmp = priority.at(i);
        priority.assign(i, priority.at(p));
        priority.assign(p, tmp);
        T tmpHeap = heap.at(i);
        heap.assign(i, heap.at(p));
        heap.assign(p, tmpHeap);
        sift_up(p);
    }
}

template<class T>
void MinHeap<T>::buildHeap() {
    int n = heap.size();
    for (int i=n/2-1; i>=0; i--) {
        sift_down(i);
    }
}

template<class T>
void MinHeap<T>::displayHeap() {
    heap.printArray();
    std::cout << "\n";
    priority.printArray();
}


/*
 * Priority_Queue class starts here
 */
template<class T>
class Priority_Queue {
private:
    MinHeap<T> heap;
public:
    Priority_Queue() { }
    void insert(T item, int priority);
    T extract_min();
    int size() { return heap.size(); }
    bool isEmpty() { return (size() == 0); }
    void display() { heap.displayHeap(); }
};

template<class T>
void Priority_Queue<T>::insert(T item, int priority) {
    heap.insert(item, priority);
    heap.sift_up(size() - 1);
}

template<class T>
T Priority_Queue<T>::extract_min() {
    T tmp = heap.extractMin();
    heap.deleteMin();
    return tmp;
}

#endif          // PRIORITY_QUEUE_H
