#include <bits/stdc++.h>

using namespace std;

// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int temp[], int l, int m, int r) {
    int i = l;
    int j = m;
    int k = l;
    while (i < m && j <= r) {
        if (arr[i] < arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }
    while (i < m) {
        temp[k++] = arr[i++];
    }
    while (j <= r) {
        temp[k++] = arr[j++];
    }
    for (int i = l; i <= r; i++) {
        arr[i] = temp[i];
    }
}

void mergeSort(int arr[], int temp[], int l, int r) {
    if (l >= r) return;
    else {
        int m = (l+r)/2;
        mergeSort(arr, temp, l, m);
        mergeSort(arr, temp, m+1, r);
        merge(arr, temp, l, m+1, r);
    }
}

int main() {
    int arr[] = { 12, 11, 13, 5, 6, 3 };
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    int temp[arr_size];
    mergeSort(arr, temp, 0, arr_size-1);
    for (int i = 0; i < arr_size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}