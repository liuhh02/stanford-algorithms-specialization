#include <bits/stdc++.h>

using namespace std;

// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
unsigned int merge(int arr[], int temp[], int l, int m, int r) {
    unsigned int inversions = 0;
    int i = l;
    int j = m;
    int k = l;
    while (i < m && j <= r) {
        if (arr[i] <= arr[j]) {
            temp[k] = arr[i];
            i++;
        } else {
            temp[k] = arr[j];
            j++;
            inversions += m-i;
        }
        k++;
    }
    while (i < m) {
        temp[k] = arr[i];
        i++;
        k++;
    }
    while (j <= r) {
        temp[k] = arr[j];
        j++;
        k++;
    }
    for (int i = l; i <= r; i++) {
        arr[i] = temp[i];
    }
    return inversions;
}

unsigned int count(int arr[], int temp[], int l, int r) {
    unsigned int inversions = 0;
    if (r > l) {
        int m = (r+l)/2;
        inversions = count(arr, temp, l, m);
        inversions += count(arr, temp, m+1, r);
        inversions += merge(arr, temp, l, m+1, r);
    }
    return inversions;
}

int main() {
    int arr_size = 100000;
    int arr[arr_size];
    ifstream file("IntegerArray.txt");
    string str;
    int i = 0;
    while (getline(file, str)) {
        arr[i] = stoi(str);
        i++;
    }
    // int arr[] = { 1, 20, 6, 4, 5 };
    // int arr_size = sizeof(arr) / sizeof(arr[0]);
    int temp[arr_size];
    /* mergeSort(arr, 0, arr_size-1);
    for (int i = 0; i < arr_size; i++) {
        cout << arr[i] << " ";
    } */
    cout << count(arr, temp, 0, arr_size-1) << endl;
}