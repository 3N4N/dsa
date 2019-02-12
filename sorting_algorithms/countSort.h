#include <iostream>
#include <climits>

void countSort(int *a, int n) {
    int max = INT_MIN;
    int min = INT_MAX;
    for (int i=0; i<n; ++i) {
        max = ( a[i] > max ) ? a[i] : max;
        min = ( a[i] < min ) ? a[i] : min;
    }
    int k = max - min + 1;
    int *b = new int[n];
    int *c = new int[k];

    for (int i=0; i<k; ++i) c[i] = 0;
    for (int i=0; i<n; ++i) c[a[i] - min]++;
    for (int i=1; i<k; ++i) c[i]+=c[i-1];

    for (int i=n-1; i>=0; --i) {
        b[c[a[i] - min] - 1] = a[i];
        c[a[i] - min]--;
    }
    for (int i=0; i<n; ++i) a[i] = b[i];
}
