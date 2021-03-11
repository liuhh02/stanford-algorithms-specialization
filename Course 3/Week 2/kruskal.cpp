#include <bits/stdc++.h>
using namespace std;

#define edge pair<int, int>

class Graph {
    private:
    vector<pair<int, edge>> G;
    vector<pair<int, edge>> T;
    int *parent;
    int *rank;
    int V;
    public:
    Graph(int V);
    void addEdge(int u, int v, int w);
    int find(int i);
    void Union(int u, int v);
    void kruskal();
    long long cost();
};

Graph::Graph(int V) {
    parent = new int[V];
    rank = new int[V];

    for (int i = 0; i < V; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    G.clear();
    T.clear();
}

void Graph::addEdge(int u, int v, int w) {
    G.push_back(make_pair(w, edge(u, v)));
}

int Graph::find(int i) {
    if (i == parent[i]) return i;
    else return find(parent[i]);
}

void Graph::Union(int u, int v) {
    if (rank[u] > rank[v]) parent[v] = parent[u];
    else if (rank[v] > rank[u]) parent[u] = parent[v];
    else {
        parent[v] = parent[u];
        rank[u]++;
    }
}

void Graph::kruskal() {
    int uSet, vSet;
    sort(G.begin(), G.end());
    for (int i = 0; i < G.size(); i++) {
        uSet = find(G[i].second.first);
        vSet = find(G[i].second.second);
        if (uSet != vSet) {
            T.push_back(G[i]);
            Union(uSet, vSet);
        }
    }
}

long long Graph::cost() {
    long long sum = 0;
    for (int i = 0; i < T.size(); i++) {
        sum += T[i].first;
    }
    return sum;
}

int main() {
    int V, E;
    ifstream file("edges.txt");
    file >> V >> E;
    Graph g(V);
    int a, b, wt;
    while (file >> a >> b >> wt) {
        g.addEdge(a-1, b-1, wt);
    }
    g.kruskal();
    cout << g.cost() << endl;
}