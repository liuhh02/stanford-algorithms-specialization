#include <bits/stdc++.h>
using namespace std;

int main() {
  vector < tuple <double, double, double> > v;
  int jobs;
  ifstream file("jobs.txt");
  file >> jobs;
  double weight, length;
  while (file >> weight >> length) {
    double ratio = weight / length;
    v.push_back(make_tuple(ratio, weight, length));
  }

  // Sort jobs in decreasing order of difference (weight - length)
  // If difference is the same, schedule job with higher weight
  sort(v.begin(), v.end());
  long long sumLength = 0;
  long long weightedSum = 0;

  for (int i = v.size() - 1; i >= 0; i--) {
    sumLength += get<2>(v[i]);
    weightedSum += sumLength * get<1>(v[i]);
  }

  cout << weightedSum << endl;
  // 67311454237
}