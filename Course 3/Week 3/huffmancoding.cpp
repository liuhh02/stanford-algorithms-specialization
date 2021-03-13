#include <bits/stdc++.h>
using namespace std;

struct MinHeapNode {
    char data;
    unsigned weight;
    MinHeapNode *left, *right;
    MinHeapNode(char data, unsigned weight) {
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

void print(struct MinHeapNode* root, string str) {
    if (!root) return;

    if (root->data != '$') cout << root->data << ": " << str << "\n";

    print(root->left, str + "0");
    print(root->right, str + "1");
}

void HuffManCodes(char data[], int weight[], int size) {
    struct MinHeapNode *left, *right, *top;

    priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap;

    for (int i = 0; i < size; i++) {
        minHeap.push(new MinHeapNode(data[i], weight[i]));
    }

    while (minHeap.size() != 1) {
        left = minHeap.top();
        minHeap.pop();

        right = minHeap.top();
        minHeap.pop();

        top = new MinHeapNode('$', left->weight + right->weight);

        top->left = left;
        top->right = right;

        minHeap.push(top);

    }
    
    print(minHeap.top(), "");
}

int main() {
    char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
    int weight[] = { 5, 9, 12, 13, 16, 45 };

    int size = sizeof(arr) / sizeof(arr[0]);

    HuffManCodes(arr, weight, size);
}