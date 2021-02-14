#include <bits/stdc++.h>

using namespace std;

int partition(int arr[], int l, int r) {
    int pivot = arr[l];
    int i = l+1;
    for (int j = l+1; j <= r; j++) {
        if (arr[j] < pivot) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
        }
    }
    arr[l] = arr[i-1];
    arr[i-1] = pivot;
    return i-1;
}

void quickSort(int arr[], int l, int r) {
    if (r <= l) return;
    int position = partition(arr, l, r);
    quickSort(arr, 0, position-1);
    quickSort(arr, position+1, r);
}

int main() {
    int arr[] = { 1, 20, 6, 4, 5, 9, 100 };
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, arr_size-1);
    for (int i = 0; i < arr_size; i++) {
        cout << arr[i] << " ";
    }
}