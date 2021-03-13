#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pi;

int main() {
    int n;
    ifstream file("huffman.txt");
    file >> n;
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    int w;
    int min;
    while (file >> w) {
        pq.push(make_pair(w, 0));
    }
    while (pq.size() != 1) {
        pair<int, int> top1 = pq.top();
        int w1 = top1.first;
        int d1 = top1.second;
        pq.pop();
        pair<int, int> top2 = pq.top();
        int w2 = top2.first;
        int d2 = top2.second;
        pq.pop();
        int w12 = w1+w2;
        int d = max(d1, d2) + 1;
        if (pq.size() == 1) cout << d2 << endl;
        if (d1 == 0 || d2 == 0) min = d;
        pq.push(make_pair(w12, d));
    }
    cout << pq.top().second << endl;
    // 19
}