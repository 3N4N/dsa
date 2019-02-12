#include <iostream>

void swap(int *arg1, int *arg2) {
    int tmp = *arg1;
    *arg1 = *arg2;
    *arg2 = tmp;
}

void selectionSort(int ara[], int n) {
    for (int i=0; i<n-1; ++i) {
        int min_idx = i;
        for (int j=i+1; j<n; ++j) {
            if (ara[j] < ara[min_idx])
                min_idx = j;
        }
        swap(&ara[i], &ara[min_idx]);
    }
}
