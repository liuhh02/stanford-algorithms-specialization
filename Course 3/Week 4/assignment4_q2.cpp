#include <bits/stdc++.h>
using namespace std;

int main() {
    int W, n;
    ifstream file("knapsack_big.txt");
    file >> W >> n;
    int v, w;
    vector< pair <int,int> > vec; 
    while (file >> v >> w) {
        vec.push_back(make_pair(v, w));
    }
    long long arr[2][W+1];
    for (int i = 0; i <= W; i++) {
        arr[0][i] = 0;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            if (vec[i-1].second > j) arr[1][j] = arr[0][j];
            else {
                arr[1][j] = max(arr[0][j], arr[0][j-vec[i-1].second] + vec[i-1].first);
            }
        }
        for (int j = 0; j <= W; j++) {
            arr[0][j] = arr[1][j];
            arr[1][j] = 0;
        }
    }
    cout << arr[0][W] << endl;
    // 4243395
}