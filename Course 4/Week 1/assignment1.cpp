#include <bits/stdc++.h>
using namespace std;

#define V 1000

void floydWarshall(int dist[V][V]) {
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k]==INT_MAX || dist[k][j]==INT_MAX) {
                    continue;
                }
                else if (dist[i][k]+dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k]+dist[k][j];
                }
            }
        }
    }
    for (int i = 0; i < V; i++) {
        if (dist[i][i] < 0) {
            cout << "Negative edge cycle detected" << endl;
            return;
        }
    }
    int min = INT_MAX;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] < min) min = dist[i][j];
        }
    }
    cout << min << endl;
}

int main() {
    int v, e;
    ifstream file("g3.txt");
    file >> v >> e;
    int dist[V][V];
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (i==j) dist[i][j] = 0;
            else dist[i][j] = INT_MAX;
        }
    }
    int src, dst, wt;
    while (file >> src >> dst >> wt) {
        dist[src-1][dst-1] = wt;
    }

    floydWarshall(dist);
}