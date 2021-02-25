#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int s, int d) {
  adj[s].push_back(d);
  adj[d].push_back(s);
}

void BFS(vector<int> adj[], int s, int V, int arr[]) {
  queue<int> Q;
  Q.push(s);
  while (!Q.empty()) {
    int v = Q.front();
    cout << v << " ";
    Q.pop();
    for (auto x : adj[v]) {
      if (arr[x] == 0) {
        arr[x] = 1;
        Q.push(x);
      }
    }
  }
}

int main() {
  int V = 5;
  vector<int> adj[V];

  addEdge(adj, 0, 1);
  addEdge(adj, 2, 3);
  addEdge(adj, 3, 4);

  int arr[V] = {0};
  
  for (int i = 0; i < V; i++) {
    if (arr[i] == 0) {
      arr[i] = 1;
      BFS(adj, i, V, arr);
      cout << endl;
    }
  }
}