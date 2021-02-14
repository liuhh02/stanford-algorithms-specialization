#include <bits/stdc++.h>

using namespace std;

void swap(int arr[], int a, int b) {
    int temp = arr[b];
    arr[b] = arr[a];
    arr[a] = temp;
}

int findMedian(int arr[], int l, int r) {
    int n = r-l+1;
    int pos = 0;
    if (n % 2 == 0) {
        pos = n/2 - 1 + l;
    } else {
        pos = n/2 + l; 
    }
    int a = arr[l];
    int b = arr[pos];
    int c = arr[r];
    if (a > b && a < c) {
        return l;
    } else if (b > a && b < c) {
        return pos;
    } else {
        return r;
    }
}

int partition(int arr[], int l, int r, int pi) {
    if (pi != 0) swap(arr, l, pi);
    int pivot = arr[l];
    int i = l+1;
    for (int j = l+1; j <= r; j++) {
        if (arr[j] < pivot) {
            swap(arr, i, j);
            i++;
        }
    }
    swap(arr, l, i-1);
    return i-1;
}

int quickSort(int arr[], int l, int r) {
    if (r <= l) return 0;
    // first element of the array is the pivot element:
    // int position = partition(arr, l, r, 0);
    // last element of the array is the pivot element:
    // int position = partition(arr, l, r, r); 
    // median element is the pivot element:
    int position = partition(arr, l, r, findMedian(arr, l, r));
    int left = quickSort(arr, 0, position-1);
    int right = quickSort(arr, position+1, r);
    return left+right+r-l;
}

int main() {
    int arr_size = 10000;
    int arr[arr_size];
    ifstream file("QuickSort.txt");
    string str;
    int i = 0;
    while (getline(file, str)) {
        arr[i] = stoi(str);
        i++;
    }

    cout << quickSort(arr, 0, arr_size-1) << endl;
}