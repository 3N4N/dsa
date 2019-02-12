#include <iostream>

void swap(int *arg1, int *arg2) {
    int tmp = *arg1;
    *arg1 = *arg2;
    *arg2 = tmp;
}

void insertionSort(int ara[], int n) {
    for (int i=1; i<n; ++i) {
        int key = ara[i];
        int j = i-1;
        while (j>=0 && ara[j]>key) {
            ara[j+1] = ara[j];
            j--;
        }
        ara[j+1] = key;
    }
}
