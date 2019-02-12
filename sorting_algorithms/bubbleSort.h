#include <iostream>

void swap(int *arg1, int *arg2) {
    int tmp = *arg1;
    *arg1 = *arg2;
    *arg2 = tmp;
}

void bubbleSort(int ara[], int n) {
    for (int i=0; i<n-1; ++i) {
        for (int j=0; j<n-1-i; ++j) {
            if (ara[j] > ara[j+1])
                swap(&ara[j], &ara[j+1]);
        }
    }
}
