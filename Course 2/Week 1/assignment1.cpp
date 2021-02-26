#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int s, int d) {
  adj[s].push_back(d);
}

// Print the graph for debugging purposes
void printGraph(vector<int> adj[], int V) {
  for (int d = 0; d < V; ++d) {
    cout << "\n Vertex "
       << d << ":";
    for (auto x : adj[d])
      cout << "-> " << x;
    printf("\n");
  }
}

void DFS(vector<int> adj[], int s, int V, int visited[], stack<int> &Stack) {
  visited[s] = 1;
  for (auto x : adj[s]) {
    if (visited[x] == 0) {
      DFS(adj, x, V, visited, Stack);
    }
  }
  Stack.push(s);
}

int DFS2(vector<int> adj[], int s, int V, int visited[], int size) {
    visited[s] = 1;
    size = 1;
    for (auto x : adj[s]) {
        if (visited[x] == 0) {
            size += DFS2(adj, x, V, visited, size);
        }
    }
    return size;
}

int main() {
  int V = 875714;
  vector<int> adj[V];
  vector<int> adj2[V];

  // to test on small test cases, load SCC_small.txt
  // and change V to 3200
  ifstream file("SCC.txt");

  int a, b;
  while (file >> a >> b) {
      addEdge(adj, a-1, b-1);
      addEdge(adj2, b-1, a-1);
  }
  //printGraph(adj, V);
  //printGraph(adj2, V);

  int visited[V] = {0};
  stack<int> Stack;

  for (int i = 0; i < V; i++) {
    if (visited[i] == 0) {
      DFS(adj, i, V, visited, Stack);
    }
  }

  for (int i = 0; i < V; i++) {
      visited[i] = 0;
  }

  int currsize = 0;
  priority_queue<int> pq;

  while (!Stack.empty()) {
    int s = Stack.top();
    Stack.pop();
    if (visited[s] == 0) {
        cout << "visiting node " << s << endl;
        int Size = DFS2(adj2, s, V, visited, currsize);
        if (pq.size() < 5) {
            pq.push(-1 * Size);
        } else {
            if (-1 * Size < pq.top()) {
                pq.pop();
                pq.push(-1 * Size);
            }
        }
    }
    
    currsize = 0;
  }
  
  while (!pq.empty()) {
      cout << -1 * pq.top() << " ";
      pq.pop();
  } 
  cout << endl;

}