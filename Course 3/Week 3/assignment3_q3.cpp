#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    ifstream file("mwis.txt");
    file >> n;
    int weight[n+1];
    int w;
    int i = 1;
    while (file >> w) {
        weight[i] = w;
        i++;
    }
    int arr[n+1];
    arr[0] = 0;
    arr[1] = weight[1];
    for (int j = 2; j <= n; j++) {
        arr[j] = max(arr[j-1], arr[j-2] + weight[j]);
    }
    set<int> s1;
    set<int>::iterator itr;
    i = n;
    while (i > 1) {
        if (arr[i-1] >= arr[i-2] + weight[i]) {
            i--;
        }
        else {
            s1.insert(i);
            i -= 2;
        }
    }
    if (i == 1) {
        if (arr[i] == weight[i]) {
            s1.insert(i);
        }
    }
    for (itr = s1.begin(); itr != s1.end(); itr++) {
        cout << *itr << " ";
    }
    cout << endl;
    // 1, 2, 3, 4, 17, 117, 517, and 997
    // 10100110
}