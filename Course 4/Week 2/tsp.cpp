#include <bits/stdc++.h>
using namespace std;

#define n 4

int VISITED_ALL = (1 << n) - 1;

int tsp(int dist[n][n], int mask, int s) {
    if (mask == VISITED_ALL) {
        return dist[s][0];
    }
    int ans = INT_MAX;

    for (int city = 0; city < n; city++) {
        if((mask&(1<<city))==0) {
            int newAns = dist[s][city] + tsp(dist, mask|(1<<city), city);
            ans = min(ans, newAns);
        }
    }
    return ans;
}

int main() {
    int dist[n][n] = {
            {0,20,42,25},
            {20,0,30,34},
            {42,30,0,10},
            {25,34,10,0}
    };
    cout << tsp(dist, 1, 0) << endl;
}