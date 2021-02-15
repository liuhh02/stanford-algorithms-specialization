#include <bits/stdc++.h>

using namespace std;

void swap(int arr[], int a, int b) {
    int temp = arr[b];
    arr[b] = arr[a];
    arr[a] = temp;
}

int partition(int arr[], int l, int r, int pi) {
    if (pi != 0) swap(arr, l, pi);
    int pivot = arr[l];
    int i = l+1;
    for (int j = l+1; j <= r; j++) {
        if (arr[j] <= pivot) {
            swap(arr, i, j);
            i++;
        }
    }
    swap(arr, l, i-1);
    return i-1;
}

// Returns the ith order statistic i.e., the ith smallest number in arr[l...r]
// NOTE that i indexing starts from 1 whereas index of partition position starts from 0
int rSelect(int arr[], int l, int r, int i) {
    if (r == l) return arr[l];
    int position = partition(arr, l, r, r);
    int k = position-l+1;
    if (i == k) return arr[position];
    else if (i < k) {
        return rSelect(arr, l, position-1, i);
    }
    else {
        return rSelect(arr, position+1, r, i-k);
    }
}

int main() {
    int arr[] = { 3, 2, 10, 6, 7, 1, 9, 5, 4, 8 };
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    cout << rSelect(arr, 0, arr_size-1, 5);
}