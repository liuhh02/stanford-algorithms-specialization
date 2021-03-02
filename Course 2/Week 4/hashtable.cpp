#include <bits/stdc++.h>
using namespace std;

int main() {
    unordered_map<long long, int> hashtable;
    int num = 9;
    long long A[num];
    ifstream file("2sumSmall.txt");
    long long in;
    int i = 0;
    while (file >> in) {
        A[i++] = in;
        hashtable[in] = 1;
    }
    int count = 0;
    
    //for (auto x : A) cout << x << " ";
    for (long long t = 3; t <= 10; t++) {
        for (int i = 0; i < num; i++) {
            long long y = t-A[i];
            cout << "y is " << y << endl;
            if (y != A[i]) {
                if (hashtable.find(y) != hashtable.end()) {
                    count++;
                    cout << "Found " << A[i] << " at position " << i << " and y = " << y << endl;
                    break;
                }
            }
            
        }
    }
    cout << count;
}