#include <bits/stdc++.h>

using namespace std;

int findMedian(int arr[], int n) {
    sort(arr, arr+n);
    return arr[n/2];
}

void swap(int arr[], int a, int b) {
    int temp = arr[b];
    arr[b] = arr[a];
    arr[a] = temp;
}

int partition(int arr[], int l, int r, int pi) {
    // search for pi
    int index; 
    for (index=l+1; index<=r; index++) 
        if (arr[index] == pi) 
           break; 
    swap(arr, l, index);
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
int dSelect(int arr[], int l, int r, int i) {
    if (r == l) return arr[l];
    int n = r-l+1;
    int numGroups = ceil(n/5); // There are numGroups each containing <= 5 numbers
    int j, median[numGroups];
    for (j = 0; j < n/5; j++) {
        median[j] = findMedian(arr+l+j*5, 5);
    }
    if (j*5 < n) {
        median[j] = findMedian(arr+l+j*5, n%5);
        j++;
    }
    int medofMed;
    if (j == 1) medofMed = median[j-1];
    else {
        medofMed = dSelect(median, 0, j-1, j/2);
    }
    int position = partition(arr, l, r, medofMed);
    int k = position-l+1;
    if (i == k) return arr[position];
    else if (i < k) {
        return dSelect(arr, l, position-1, i);
    }
    else {
        return dSelect(arr, position+1, r, i-k);
    }
}

int main() {
    //int arr[] = { 3, 2, 10, 6, 7, 1, 9, 5, 4, 8 };
    int arr[] = {12, 3, 5, 7, 4, 19, 26, 30, 63, 38}; 
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    cout << dSelect(arr, 0, arr_size-1, 10);
}