#include <bits/stdc++.h>
using namespace std;
#define V 200

int source(int shortestDist[], int visited[]) {
  int minDist = INT_MAX, index;
  for (int i = 0; i < V; i++) {
    if (visited[i] == 0 && shortestDist[i] <= minDist) {
      minDist = shortestDist[i];
      index = i;
    }
  }
  return index;
}

void dijkstra(int adj[V][V], int s) {
  int visited[V];
  int shortestDist[V];
  for (int i = 0; i < V; i++) {
    shortestDist[i] = INT_MAX;
    visited[i] = 0;
  }
  shortestDist[s] = 0;
  for (int i = 0; i < V-1; i++) {
    int w = source(shortestDist, visited);
    visited[w] = 1;
    for (int j = 0; j < V; j++) {
      if (visited[j] == 0 && adj[w][j] && shortestDist[w] != INT_MAX && shortestDist[w] + adj[w][j] < shortestDist[j]) {
        shortestDist[j] = shortestDist[w] + adj[w][j];
      }
    }
  }
  // print out all shortest distances
  /* for (int i = 0; i < V; i++) {
    cout << shortestDist[i] << endl;
  } */
  int list[10] = {7,37,59,82,99,115,133,165,188,197};
  for (int i = 0; i < 10; i++) {
    cout << shortestDist[list[i]-1] << ",";
  }
}

int main() {
  int adj[V][V] = {0};
  ifstream file("dijkstraData.txt");
  string str;
  while (getline(file, str)) {
    istringstream iss(str);
    int source;
    iss >> source;
    // cout << "source is " << source-1 << endl;
    int end, l;
    char comma;
    while ( iss >> end >> comma >> l ) {
      adj[source-1][end-1] = l;
      // cout << "end is " << end-1 << " and length is " << l << endl;
    }
  }
  
  // print out adjacency matrix
  /* for (int i = 0; i < V; i++) {
    for (int j = 0; j < V; j++) {
      cout << adj[i][j] << " ";
    }
    cout << endl;
  } */

  dijkstra(adj, 0);
}
