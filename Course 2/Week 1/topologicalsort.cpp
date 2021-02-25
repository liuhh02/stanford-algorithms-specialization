#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int s, int d) {
  adj[s].push_back(d);
}

void DFS(vector<int> adj[], int s, int V, int visited[], stack<int> &order) {
  visited[s] = 1;
  for (auto x : adj[s]) {
    if (visited[x] == 0) {
      DFS(adj, x, V, visited, order);
    }
  }
  order.push(s);
}

int main() {
  int V = 6;
  vector<int> adj[V];

  addEdge(adj, 4, 2);
  addEdge(adj, 5, 1);
  addEdge(adj, 4, 0);
  addEdge(adj, 3, 1);
  addEdge(adj, 1, 3);
  addEdge(adj, 3, 2);

  int visited[V] = {0};
  stack<int> order;

  for (int i = 0; i < V; i++) {
    if (visited[i] == 0) {
      DFS(adj, i, V, visited, order);
    }
    
  }

  while (order.empty() == false) {
    cout << order.top() << " ";
    order.pop();
  }

  cout << endl;
}