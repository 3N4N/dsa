#include <iostream>

#ifndef NULL_VALUE
#define NULL_VALUE -99999
#endif

template <class T>
class ArrayList
{
public:
  ArrayList (int);        // create arraylist with given capacity
  virtual ~ArrayList ();  // delete arraylist and release memory
  int size();             // return current size
  void add(T);            // insert item at the end
  void insertAt(int, T);  // insert item at given position
  void remove(T);         // remove first occurrence of given item
  void removeAllOf(T);    // remove all occurrence of given item
  void removeAt(int);     // remove item at given position
  int search(T);          // return index of first occurrence of given item
  int rsearch(T);         // backward search
  T at(int);              // return item at given position
  void clear();           // remove all items
  void printArray();      // print the items in the arraylist

private:
  void expand();
  void shrink();
  T * arr;
  int length;
  int capacity;
};

template <class T>
ArrayList<T>::ArrayList(int capacity) {
  if (capacity <= 0) capacity = 1;
  this->capacity = capacity;
  arr = new T[ capacity ];
  length=0;
}

template <class T>
ArrayList<T>::~ArrayList () {
  delete(arr);
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

  delete(arr);
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

  delete(arr);
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
