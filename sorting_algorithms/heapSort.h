#include <iostream>

void swap(int *arg1, int *arg2) {
    int tmp = *arg1;
    *arg1 = *arg2;
    *arg2 = tmp;
}

void heapify(int ara[], int n, int i) {
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int largest = i;
    if (l < n && ara[l] > ara[largest])
        largest = l;
    if (r < n && ara[r] > ara[largest])
        largest = r;
    if (largest != i) {
        swap(&ara[i], &ara[largest]);
        heapify(ara, n, largest);
    }
}

void buildHeap(int ara[], int n) {
    for (int i=n/2-1; i>=0; i--) {
        heapify(ara, n, i);
    }
}

void heapSort(int ara[], int n) {
    buildHeap(ara, n);
    for (int i=n-1; i>=0; i--) {
        swap(&ara[i], &ara[0]);
        heapify(ara, i, 0);
    }
}
