#include <iostream>

void merge(int ara[], int l, int m, int r) {
    int n1 = m-l+1;
    int n2 = r-m;
    int L[n1], R[n2];
    for (int i=0; i<n1; ++i)
        L[i] = ara[l+i];
    for (int i=0; i<n2; ++i)
        R[i] = ara[m+1+i];

    int i,j,k;
    i = j = 0;
    k = l;
    while (i<n1 && j<n2) {
        if (L[i] <= R[j]) {
            ara[k] = L[i];
            i++;
        } else {
            ara[k] = R[j];
            j++;
        }
        k++;
    }
    while (i<n1) {
        ara[k] = L[i];
        i++;
        k++;
    }
    while (j<n2) {
        ara[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int ara[], int lo, int hi) {
    if (lo >= hi) return;
    int mid = (lo+hi)/2;
    mergeSort(ara, lo, mid);
    mergeSort(ara, mid+1, hi);
    merge(ara, lo, mid, hi);
}

void mergeSort(int ara[], int n) {
    mergeSort(ara, 0, n-1);
}
