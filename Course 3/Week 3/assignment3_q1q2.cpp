#include <bits/stdc++.h>
using namespace std;

struct MinHeapNode {
    int data;
    unsigned weight;
    MinHeapNode *left, *right;
    MinHeapNode(int data, unsigned weight) {
        left = right = NULL;
        this->data = data;
        this->weight = weight;
    }
};

struct compare {
    bool operator()(MinHeapNode* l, MinHeapNode* r) {
        return (l->weight > r->weight);
    }
};

int maxDepth(struct MinHeapNode* root) {
    if (!root) return -1;

    else {
        int lDepth = maxDepth(root->left);
        int rDepth = maxDepth(root->right);

        return max(lDepth, rDepth) + 1;
    }
}

int minDepth(struct MinHeapNode* root) {
    if (!root) return -1;

    else {
        int lDepth = minDepth(root->left);
        int rDepth = minDepth(root->right);

        return min(lDepth, rDepth) + 1;
    }
}

int main() {
    struct MinHeapNode *left, *right, *top;

    priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap;

    int n;
    ifstream file("huffman.txt");
    file >> n;
    int w;
    while (file >> w) {
        minHeap.push(new MinHeapNode(w, w));
    }

    while (minHeap.size() != 1) {
        left = minHeap.top();
        minHeap.pop();

        right = minHeap.top();
        minHeap.pop();

        top = new MinHeapNode(-1, left->weight + right->weight);

        top->left = left;
        top->right = right;

        minHeap.push(top);

    }
    
    cout << "Max Length: " << maxDepth(minHeap.top()) << endl; // 19
    cout << "Min Length: " << minDepth(minHeap.top()) << endl; // 9
}