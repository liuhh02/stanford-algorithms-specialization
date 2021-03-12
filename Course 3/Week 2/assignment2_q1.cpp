#include <bits/stdc++.h>
using namespace std;

#define edge pair<int, int>

class Graph {
    private:
    vector<pair<int, edge>> G;
    int *parent;
    int *rank;
    int V;
    public:
    Graph(int V);
    void addEdge(int u, int v, int w);
    int numClusters();
    int find(int i);
    void Union(int u, int v);
    void clustering(int k);
};

Graph::Graph(int V) {
    parent = new int[V];
    rank = new int[V];

    for (int i = 0; i < V; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    G.clear();
}

void Graph::addEdge(int u, int v, int w) {
    G.push_back(make_pair(w, edge(u, v)));
}

int Graph::numClusters() {
    int count = 0;
    for (int i =0; i < G.size(); i++) {
        if (i == parent[i]) count++;
    }
    return count;
}

int Graph::find(int i) {
    if (i == parent[i]) return i;
    else return find(parent[i]);
}

void Graph::Union(int u, int v) {
    if (rank[u] > rank[v]) {
        parent[v] = parent[u];
        rank[u]++;
    }
    else if (rank[v] > rank[u]) {
        parent[u] = parent[v];
        rank[v]++;
    }
    else {
        parent[v] = parent[u];
        rank[u]++;
    }
}

void Graph::clustering(int k) {
    int uSet, vSet;
    int i = 0;
    sort(G.begin(), G.end());
    while (k != numClusters()) {
        uSet = find(G[i].second.first);
        vSet = find(G[i].second.second);
        if (uSet != vSet) {
            Union(uSet, vSet);
        }
        i++;
    }
    do {
        uSet = find(G[i].second.first);
        vSet = find(G[i].second.second);
        i++;
    } while (uSet == vSet);
    cout << G[i-1].first;
    // uSet = find(G[i].second.first);
    // vSet = find(G[i].second.second);
    // while (uSet != vSet)
    // for (int i = 0; i < G.size(); i++) {
    //     uSet = find(G[i].second.first);
    //     vSet = find(G[i].second.second);
    //     if (k == numClusters()) {
    //         cout << "Done" << endl;
    //         if (uSet != vSet) {
    //             cout << G[i].first;
    //             break;
    //         }
    //     }
    //     else {
    //         if (uSet != vSet) {
    //             Union(uSet, vSet);
    //         }
    //     }
}

int main() {
    int V;
    ifstream file("clustering1.txt");
    file >> V;
    Graph g(V);
    int a, b, wt;
    while (file >> a >> b >> wt) {
        g.addEdge(a-1, b-1, wt);
    }
    g.clustering(4);
}
