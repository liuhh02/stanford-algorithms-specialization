#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int s, int d) {
  adj[s].push_back(d);
  adj[d].push_back(s);
}

void BFS(vector<int> adj[], int s, int V, int dist[], int prev[]) {
  int visited[V] = {0};
  visited[s] = 1;
  dist[s] = 0;
  queue<int> Q;
  Q.push(s);
  while (!Q.empty()) {
    int v = Q.front();
    cout << v << " ";
    Q.pop();
    for (auto x : adj[v]) {
      if (visited[x] == 0) {
        visited[x] = 1;
        dist[x] = dist[v] + 1;
        prev[x] = v;
        Q.push(x);
      }
    }
  }
}

void printPath(vector<int> adj[], int s, int V, int dist[], int prev[], int d) {
  BFS(adj, s, V, dist, prev);
  cout << endl;
  cout << "Shortest distance from 0 to " << d << " is " << dist[d] << endl;
  vector<int> path;
  int curr = d;
  path.push_back(curr);
  while (prev[curr] != -1) {
    path.push_back(prev[curr]);
    curr = prev[curr];
  }
  cout << "Path is: ";
  for (int i = path.size() - 1; i >= 0; i--) {
    cout << path[i] << " ";
  }
}

int main() {
  int V = 8;
  vector<int> adj[V];
  int dist[V] = {-1};
  int prev[V] = {-1};
  addEdge(adj, 0, 1);
  addEdge(adj, 0, 3);
  addEdge(adj, 1, 2);
  addEdge(adj, 3, 4);
  addEdge(adj, 3, 7);
  addEdge(adj, 4, 5);
  addEdge(adj, 4, 6);
  addEdge(adj, 4, 7);
  addEdge(adj, 5, 6);
  addEdge(adj, 6, 7);

  printPath(adj, 0, V, dist, prev, 7);
  cout << endl;
}