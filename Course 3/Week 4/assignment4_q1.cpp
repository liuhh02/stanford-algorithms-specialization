#include <bits/stdc++.h>
using namespace std;

int main() {
    int W, n;
    ifstream file("knapsack1.txt");
    file >> W >> n;
    int v, w;
    vector< pair <int,int> > vec; 
    while (file >> v >> w) {
        vec.push_back(make_pair(v, w));
    }
    int arr[n+1][W+1];
    for (int i = 0; i <= W; i++) {
        arr[0][i] = 0;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            if (vec[i-1].second > j) arr[i][j] = arr[i-1][j];
            else {
                arr[i][j] = max(arr[i-1][j], arr[i-1][j-vec[i-1].second] + vec[i-1].first);
            }
        }
    }
    cout << arr[n][W] << endl;
    // 2493893
}