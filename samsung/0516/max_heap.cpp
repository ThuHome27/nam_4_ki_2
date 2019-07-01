//
// Created by tony on 3/7/19.
//

#include <iostream>
#define MAX_N 100

using  namespace std;

int n, a[MAX_N];

void heapify(int arr[],int size, int root) {
    int largest = root;
    int l = root * 2 + 1;
    int r = l + 1;
    if (l < size && arr[l] > arr[largest]) {
        largest = l;
    }
    if (r < size && arr[r] > arr[largest]) {
        largest = r;
    }

    if (largest != root) {
        swap(a[largest], a[root]);
        heapify(arr, size, largest);
    }
}

void mheap_sort(int arr[], int size) {
    for (int i = n / 2 - 1; i >= 0; --i) {
        heapify(arr, size, i);
    }
    for (int i = size - 1; i >= 0; --i) {
        swap(arr[i], arr[0]);
        heapify(arr, i, 0);
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    mheap_sort(a, n);
    for (int i = 0; i < n; ++i) {
        cout << a[i] << ' ';
    }
    return 0;
}