// Implementation of Kosaraju's Algorithm to find
// Strongly Connected Components for 2 SAT problem
#include <bits/stdc++.h>
using namespace std;

const int MAX = 2000001;

vector<int> adj[MAX];
vector<int> adjInv[MAX];
bool visited[MAX];
bool visitedInv[MAX];
stack<int> s;

int scc[MAX];

int counter = 1;

void addEdges(int a, int b) {
    adj[a].push_back(b);
}

void addEdgesInv(int a, int b) {
    adjInv[b].push_back(a);
}

void dfs(int u) {
    if (visited[u]) return;

    visited[u] = 1;

    for (int i = 0; i < adj[u].size(); i++) {
        dfs(adj[u][i]);
    }
    
    s.push(u);
}

void dfsInv(int u) {
    if (visitedInv[u]) return;

    visitedInv[u] = 1;

    for (int i = 0; i < adjInv[u].size(); i++) {
        dfsInv(adjInv[u][i]);
    }

    scc[u] = counter;
}

int main() {
    int n;
    ifstream file("2sat6.txt");
    file >> n;
    int a, b;
    while (file >> a >> b) {
        if (a > 0 && b > 0) {
            addEdges(a+n, b);
            addEdgesInv(a+n, b);
            addEdges(b+n, a);
            addEdgesInv(b+n, a);
        }
        else if (a > 0 && b < 0) {
            addEdges(a+n, n-b);
            addEdgesInv(a+n, n-b);
            addEdges(-b, a);
            addEdgesInv(-b, a);
        }
        else if (a < 0 && b > 0) {
            addEdges(-a, b);
            addEdgesInv(-a, b);
            addEdges(b+n, n-a);
            addEdgesInv(b+n, n-a);
        }
        else {
            addEdges(-a, n-b);
            addEdgesInv(-a, n-b);
            addEdges(-b, n-a);
            addEdgesInv(-b, n-a);
        }
    }
    
    for (int i = 1; i <= 2*n; i++) {
        if (!visited[i]) dfs(i);
    }
    
    while (!s.empty()) {
        int k = s.top();
        s.pop();

        if (!visitedInv[k]) {
            dfsInv(k);
            counter++;
        }
    }

    bool satisfiable = true;

    for (int i = 1; i <= n; i++) {
        if (scc[i] == scc[i+n]) {
            cout << "Unsatisfiable" << endl;
            satisfiable = false;
            break;
        }
    }
    if (satisfiable) cout << "Satisfiable" << endl;
}