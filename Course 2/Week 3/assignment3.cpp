#include <bits/stdc++.h>
using namespace std;
 
// Program to Output Median of Stream of Integers using Max Heap & Min Heap
int main ()
{
    priority_queue <int, vector<int>, greater<int> > minHeap;
    priority_queue <int> maxHeap;
    maxHeap.push(0);
    minHeap.push(99999);
    int medianSum = 0;
    ifstream file("Median.txt");
    string str;
    while (getline(file, str)) {
        istringstream iss(str);
        int num;
        iss >> num;
        if (minHeap.size() > maxHeap.size()) {
            if (num > minHeap.top()) {
                maxHeap.push(minHeap.top());
                minHeap.pop();
                minHeap.push(num);
            } 
            else maxHeap.push(num);
            // cout << "median is " << maxHeap.top() << endl;
            medianSum = (medianSum + maxHeap.top()) % 10000;
        } else if (maxHeap.size() > minHeap.size()) {
            if (num < maxHeap.top()) {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
                maxHeap.push(num);
            } 
            else minHeap.push(num);
            // cout << "median is " << maxHeap.top() << endl;
            medianSum = (medianSum + maxHeap.top()) % 10000;
        } 
        else { // maxHeap.size() == minHeap.size()
            if (num > minHeap.top()) {
                minHeap.push(num);
                // cout << "median is " << minHeap.top() << endl;
                medianSum = (medianSum + minHeap.top()) % 10000;
            }
            else {
                maxHeap.push(num);
                // cout << "median is " << maxHeap.top() << endl;
                medianSum = (medianSum + maxHeap.top()) % 10000;
            }
        }
    }
    cout << medianSum;
}