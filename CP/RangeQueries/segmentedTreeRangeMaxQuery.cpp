#include<bits/stdc++.h>

using namespace std;

// Global variable
vector<int> tree;

// Build segmented tree with nums
void buildSegmentTree(vector<int> nums, int idx, int lo, int hi) {
    if (lo == hi) {
        tree[idx] = nums[lo];
        return;
    }
    int mid = lo + (hi-lo)/2;
    buildSegmentTree(nums, 2*idx+1, lo, mid);
    buildSegmentTree(nums, 2*idx+2, mid+1, hi);
    tree[idx] = max(tree[2*idx+1], tree[2*idx+2]);
}

// Update tree values
void updateTree(int node, int start, int end, int idx, int delta) {
    if (start == end) {
        tree[node] += delta;
        return;
    }
    int mid = start + (end - start) / 2;
    int leftChild = 2 * node + 1;
    int rightChild = 2 * node + 2;
    if (idx >= start && idx <= mid) updateTree(leftChild, start, mid, idx, delta);
    else updateTree(rightChild, mid + 1, end, idx, delta);
    tree[node] = max(tree[leftChild], tree[rightChild]);
}

// Get the range sum recursively
int getRangeMax(int idx, int start, int end, int left, int right) {
    if (start > right || end < left) return INT_MIN;
    if (start >= left && end <= right) return tree[idx];
    int mid = start+(end-start) / 2;
    int maxLeft = getRangeMax(2*idx+1, start, mid, left, right);
    int maxRight = getRangeMax(2*idx+2, mid + 1, end, left, right);
    return max(maxLeft, maxRight);
}

vector<int> findRangeMax(vector<int> &nums, vector<vector<int>> &queries) {
    vector<int> res;
    tree.resize(2*nums.size());
    buildSegmentTree(nums, 0, 0, nums.size()-1);
    for (auto &query: queries) {
        if (query[0] == 0) res.push_back(getRangeMax(0, 0, nums.size()-1, query[1], query[2]));
        else updateTree(0, 0, nums.size()-1, query[1], query[2]);
    }
    return res;
}

int main() {
    vector<int> nums{1, 3, 4, 3, 4, 1, 34, 3, 2, 1, 2, 14, -45, 45, 5, 38, -987};
    //               0, 1, 2, 3, 4, 5,  6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16
    vector<vector<int>> queries{{0, 1,5}, {0, 12, 13}, {1, 15, 500}, {0, 1, 15}}; // 3, -45, -45
    for (auto x: findRangeMax(nums, queries)) cout<<x<<" ";
    cout<<endl;
    return 0;
}