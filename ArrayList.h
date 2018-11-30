#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H


#include <iostream>

#define NULL_VALUE -99999

template <class T>
class ArrayList
{
public:
    ArrayList ();                    // default constructor with capacity 2
    ArrayList (int capacity);        // create arraylist with given capacity
    virtual ~ArrayList ();           // delete arraylist and release memory
    int size();                      // return current size
    void add(T value);               // insert item at the end
    void insertAt(int pos, T value); // insert item at given position
    void remove(T value);            // remove first occurrence of given item
    void removeAllOf(T value);       // remove all occurrence of given item
    void removeAt(int pos);          // remove item at given position
    int search(T value);             // return index of first occurrence of given item
    int rsearch(T value);            // backward search
    T at(int pos);                   // return item at given position
    void assign(int pos, T value);   // change value at position pos
    void clear();                    // remove all items
    void printArray();               // print the items in the arraylist

private:
    void expand();
    void shrink();
    T * arr;
    int length;
    int capacity;
};

template <class T>
ArrayList<T>::ArrayList() {
    this->capacity = 2;
    arr = new T[ capacity ];
    length=0;
}

template <class T>
ArrayList<T>::ArrayList(int capacity) {
    if (capacity <= 0) capacity = 1;
    this->capacity = capacity;
    arr = new T[ capacity ];
    length=0;
}

template <class T>
ArrayList<T>::~ArrayList () {
    if (arr) delete[] arr;
    length = 0;
    arr = NULL;
}

template <class T>
int ArrayList<T>::size() {
    return length;
}

template <class T>
void ArrayList<T>::expand() {
    if (size() < capacity)
        return ;

    capacity *= 2;
    int len = size();

    int * tmpList = new int[ capacity ];
    for (int i=0; i<len; ++i) {
        tmpList[i] = arr[i];
    }

    if(arr) delete[] arr;
    arr = tmpList;
}

template <class T>
void ArrayList<T>::shrink() {
    if (size() > capacity/2)
        return ;

    capacity /= 2;
    int len = size();

    int * tmpList = new int[ capacity ];
    for (int i=0; i<len; ++i) {
        tmpList[i] = arr[i];
    }

    if (arr) delete[] arr;
    arr = tmpList;
}

template <class T>
void ArrayList<T>::add(T value) {
    if (size() >= capacity)
        expand();

    arr[length] = value;
    length++;
}

template <class T>
void ArrayList<T>::insertAt(int pos, T value) {
    if (pos < 0 || pos > size()) return ;

    if (size() >= capacity)
        expand();

    for (int i=length; i>pos; --i)
        arr[i] = arr[i-1];
    arr[pos] = value;
    length++;
}

template <class T>
void ArrayList<T>::remove(T value) {
    int len = size();
    for (int i=0; i<len; ++i) {
        if (arr[i] != value)
            continue;

        for (int j=i; j<len; ++j)
            arr[j] = arr[j+1];

        length--;
        break;
    }
    if (size() <= capacity/2) shrink();
}

template <class T>
void ArrayList<T>::removeAllOf(T value) {
    int len = size();
    for (int i=0; i<len; ++i) {
        if (arr[i] != value)
            continue;

        for (int j=i; j<len; ++j)
            arr[j] = arr[j+1];

        length--;
        i--;
    }
    if (size() <= capacity/2) shrink();
}

template <class T>
void ArrayList<T>::removeAt(int pos) {
    if ( pos < 0 || pos >= size() ) return ;

    int len = size();
    for (int i=pos; i<len; ++i) {
        arr[i] = arr[i+1];
    }
    length--;
    if (size() <= capacity/2) shrink();
}

template <class T>
int ArrayList<T>::search(T value) {
    int len = size();
    for (int i=0; i<len; ++i) {
        if (arr[i] == value) return i;
    }
    return -1;
}

template <class T>
int ArrayList<T>::rsearch(T value) {
    int len = size();
    for (int i=len-1; i>=0; --i) {
        if (arr[i] == value) return i;
    }
    return -1;
}

template <class T>
T ArrayList<T>::at(int pos) {
    if ( pos < 0 || pos >= size() )
        return NULL_VALUE;
    return arr[pos];
}

template <class T>
void ArrayList<T>::assign(int pos, T value) {
    arr[pos] = value;
}

template <class T>
void ArrayList<T>::clear() {
    length = 0;
    shrink();
}

template <class T>
void ArrayList<T>::printArray() {
    int len = size();
    if (len==0) {
        std::cout << "Arraylist is empty" << std::endl;
        return ;
    }
    for (int i=0; i<len-1; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << arr[len-1] << std::endl;
}

#endif          // ARRAY_LIST_H
