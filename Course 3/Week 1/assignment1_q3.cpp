#include <bits/stdc++.h>
using namespace std;

// Add edge
void addEdge(vector <pair<int, int>> adj[], int s, int d, int wt) {
  adj[s].push_back(make_pair(d, wt));
  adj[d].push_back(make_pair(s, wt));
}

int findMinVertex(vector <int>& value, vector<bool>& visited, int V) {
  int minimum = INT_MAX;
  int vertex;
  for (int i=0; i < V; i++) {
    if (!visited[i] && value[i]<minimum) {
      minimum = value[i];
      vertex = i;
    }
  }
  return vertex;
}

int main() {
  int V, E;
  ifstream file("edges.txt");
  file >> V >> E;
  int a, b, wt;
  int graph[V][V];
  memset(graph, 0, sizeof graph);
  while (file >> a >> b >> wt) {
      graph[a-1][b-1] = wt;
      graph[b-1][a-1] = wt;
  }
  vector<bool> visited(V, false);
  vector<int> value(V, INT_MAX);
  int parent[V];
  parent[0] = -1;
  value[0] = 0;
  for (int i = 0; i < V-1; i++) {
    int d = findMinVertex(value, visited, V);
    visited[d] = true;
    for (int j = 0; j < V; j++) {
      if (!visited[j] && graph[d][j]!=0 && graph[d][j]<value[j]) {
        value[j] = graph[d][j];
        parent[j] = d;
      }
    }
  }
  long long cost = 0;
  for (int i = 1; i < V; i++) {
    cost += graph[i][parent[i]];
  }
  cout << cost << endl;
  // -3612829
}