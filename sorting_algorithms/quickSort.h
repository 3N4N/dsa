#include <iostream>

void swap(int *arg1, int *arg2) {
    int tmp = *arg1;
    *arg1 = *arg2;
    *arg2 = tmp;
}

int partition(int ara[], int lo, int hi) {
    int i=lo;
    int pivot = ara[hi];
    for (int j=lo; j<hi; ++j) {
        if (ara[j] < pivot) {
            swap(&ara[j], &ara[i]);
            i++;
        }
    }
    swap(&ara[i], &ara[hi]);
    return i;
}

void quickSort(int ara[], int lo, int hi) {
    if (lo >= hi) return;
    int pivot_index = partition(ara, lo, hi);
    quickSort(ara, lo, pivot_index-1);
    quickSort(ara, pivot_index+1, hi);
}

void quickSort(int ara[], int n) {
    quickSort(ara, 0, n-1);
}
