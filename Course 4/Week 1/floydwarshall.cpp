#include <bits/stdc++.h>
using namespace std;

#define V 6

void floydWarshall(int graph[V][V]) {
    int dist[V][V];

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            dist[i][j] = graph[i][j];
        }
    }

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
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cout << "Distance from " << i << " to " << j << " is " << dist[i][j] << endl;
        }
    }
}

int main() {
    int graph[V][V] = { {0, 1, 4, INT_MAX, INT_MAX, INT_MAX},
						{INT_MAX, 0, 4, 2, 7, INT_MAX},
						{INT_MAX, INT_MAX, 0, 3, 4, INT_MAX},
						{INT_MAX, INT_MAX, INT_MAX, 0, INT_MAX, 4},
						{INT_MAX, INT_MAX, INT_MAX, 3, 0, INT_MAX},
						{INT_MAX, INT_MAX, INT_MAX, INT_MAX, 5, 0} };
    floydWarshall(graph);
}