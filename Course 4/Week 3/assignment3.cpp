/* You should implement the nearest neighbor heuristic:

1. Start the tour at the first city.
2. Repeatedly visit the closest city that the tour hasn't visited yet.  In case of a tie, go to the closest city with the lowest index.  For example, if both the third and fifth cities have the same distance from the first city (and are closer than any other city), then the tour should begin by going from the first city to the third city.
3. Once every city has been visited exactly once, return to the first city to complete the tour.
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    ifstream file("nn.txt");
    file >> n;

    bool visited[n] = {0};

    int index;
    double x, y;
    vector<pair <double, double>> v;
    while (file >> index >> x >> y) {
        v.push_back(make_pair(x, y));
    }
    double total_dist = 0.0;
    int src = 0;
    int num_visited = 1;
    int dest;
    visited[0] = true;
    double min_dist = DBL_MAX;
    while (num_visited < n) {
        for (int i = 1; i < n; i++) {
            if (!visited[i]) {
                // cout << i+1 << " not visited yet." << endl;
                double dist = sqrt((v[src].first - v[i].first) * (v[src].first - v[i].first) + (v[src].second - v[i].second) * (v[src].second - v[i].second));
                if (dist < min_dist) {
                    min_dist = dist;
                    dest = i;
                    // cout << "Visiting " << dest+1 << endl;
                }
                /*else if (dist >= min_dist) {
                    if (v[i].first!=v[i-1].first) {
                        total_dist += min_dist;
                        visited[dest] = true;
                        // cout << "Going from " << src+1 << " to " << dest+1 << ". Distance = " << total_dist << endl;
                        src = dest;
                        min_dist = DBL_MAX;
                        num_visited++;
                        break;
                    }
                }*/
            }
        }
        total_dist += min_dist;
        visited[dest] = true;
        src = dest;
        min_dist = DBL_MAX;
        num_visited++;
        if (num_visited % 100 == 0) cout << "visited " << num_visited << endl;
    }
    total_dist += sqrt((v[src].first - v[0].first) * (v[src].first - v[0].first) + (v[src].second - v[0].second) * (v[src].second - v[0].second));

    cout << total_dist << endl;
    cout << fixed;
    cout << total_dist << endl;
}