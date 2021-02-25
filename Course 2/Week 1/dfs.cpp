#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int s, int d) {
  adj[s].push_back(d);
}

void DFS(vector<int> adj[], int s, int V, int visited[]) {
  visited[s] = 1;
  cout << s << " ";
  for (auto x : adj[s]) {
    if (visited[x] == 0) {
      DFS(adj, x, V, visited);
    }
  }
}

int main() {
  int V = 4;
  vector<int> adj[V];

  addEdge(adj, 0, 1);
  addEdge(adj, 0, 2);
  addEdge(adj, 1, 2);
  addEdge(adj, 2, 0);
  addEdge(adj, 2, 3);
  addEdge(adj, 3, 3);

  int visited[V] = {0};
  DFS(adj, 2, V, visited);

  cout << endl;
}