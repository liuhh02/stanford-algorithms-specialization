#include <bits/stdc++.h>
using namespace std;

struct Edge {
  int src, dest;
};

struct Graph {
  int V, E;
  Edge* edge;
};

struct subset {
  int parent;
  int rank;
};

int find(struct subset subsets[], int i) {
  if (subsets[i].parent != i) {
    subsets[i].parent = find(subsets, subsets[i].parent);
  }
  return subsets[i].parent;
}

void Union(struct subset subsets[], int x, int y) {
  int xroot = find(subsets, x);
  int yroot = find(subsets, y);

  if (subsets[xroot].rank < subsets[yroot].rank) {
    subsets[xroot].parent = yroot;
  } else if (subsets[xroot].rank > subsets[yroot].rank) {
    subsets[yroot].parent = xroot;
  } else {
    subsets[yroot].parent = xroot;
    subsets[xroot].rank++;
  }
}

int randomContraction(struct Graph* graph) {
  int V = graph->V, E = graph->E;
  Edge *edge = graph->edge;

  struct subset *subsets = new subset[V];

  for (int v = 0; v < V; v++) {
    subsets[v].parent = v;
    subsets[v].rank = 0;
  }

  int vertices = V;
  while (vertices > 2) {
    int i = rand() % E;

    int subset1 = find(subsets, edge[i].src);
    int subset2 = find(subsets, edge[i].dest);

    if (subset1 == subset2) continue;
    else {
      Union(subsets, subset1, subset2);
      vertices--;
    }
  }
  int cutEdges = 0;
  for (int i=0; i<E; i++) {
    int subset1 = find(subsets, edge[i].src);
    int subset2 = find(subsets, edge[i].dest);
    if (subset1 != subset2) cutEdges++;
  }
  return cutEdges;
}

struct Graph* createGraph(int V, int E) {
  Graph* graph = new Graph;
  graph->V = V;
  graph->E = E;
  graph->edge = new Edge[E];
  return graph;
}

int main() {
  srand((unsigned)time(NULL));
  int V = 200;

  ifstream file("kargerMinCut.txt");
  string str;
  int val;
  int E = 0;
  // first loop through to find the number of edges
  while (getline(file, str)) {
    istringstream iss(str);
    string c;
    iss >> c;
    int i = stoi(c);
    while (iss >> val) { 
      if (val > i) E++; // so each edge only gets counted once
    }
  } 
  file.clear();
  file.close();
  // cout << "number of edges is " << E << endl;
  struct Graph* graph = createGraph(V, E);
  ifstream file2("kargerMinCut.txt");
  string str2;
  int val2;
  int edgeCount = 0;
  while (getline(file2, str2)) {
    istringstream iss(str2);
    string c2;
    iss >> c2;
    int vertex = stoi(c2);
    while (iss >> val2) {
      if (val2 > vertex) {
        graph->edge[edgeCount].src = vertex-1; 
        graph->edge[edgeCount].dest = val2-1; 
        edgeCount++;
      } 
    }
  }
  int minContractions = 1000000;
  for (int i = 0; i < 200; i++) {
    int calculated = randomContraction(graph);
    if (calculated < minContractions) {
      minContractions = calculated;
    }
  }
  cout << minContractions << endl;
}
