#include <bits/stdc++.h>
using namespace std;

int main() {
    int size = 9;
    int lower = 3;
    int upper = 10;
    long long A[size];
    ifstream file("2sumSmall.txt");
    long long in;
    int k = 0;
    while (file >> in) {
        A[k++] = in;
    }
    sort(A, A+size);
    cout << "sorted" << endl;
    int i = 0;
    int j = size-1;
    int count = 0;
    unordered_map<int, bool> sumList;
    while (i < j) {
        if (A[i] + A[j] < lower) i++;
        else if (A[i] + A[j] > upper) j--;
        else {
            for (int pos = i+1; pos <= j; pos++) {
                int sum = A[i] + A[pos];
                if (sum > upper) break;
                else if (A[i] != A[pos] && sum >= lower) {
                    if (sumList[sum] == 0) {
                        count++;
                        sumList[sum] = 1;
                        cout << "sum is " << A[i] << "+" << A[pos] << "=" << sum << endl;
                    }
                }
            }
            i++;
        }
    }
    
    cout << count;
}