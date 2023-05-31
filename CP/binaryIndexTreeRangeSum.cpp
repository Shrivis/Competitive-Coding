#include<bits/stdc++.h>
using namespace std;

// global variables
vector<int> tree;

void update(int index, int delta, int n) {
    index++; // becuase there is 1 based indexing in tree 
    while (index <= n) {
        tree[index] += delta;
        index += index&-index;
    }
}

int getRangeSum(int index) {
    index++; // becuase there is 1 based indexing in tree 
    int result = 0;
    while (index > 0) {
        result += tree[index];
        index -= index&-index;
    }
    return result;
}

vector<int> findSumInRange(vector<int> &nums, vector<vector<int>> queries) {
    tree.resize(nums.size()+1);
    vector<int> res;

    // precomputation
    for (int i=0; i<(int)nums.size();++i) {
        update(i, nums[i], nums.size());
    }
    for (auto query: queries) {
        if (query[0] == 0) res.push_back(getRangeSum(query[2]) - getRangeSum(query[1] - 1));
        else update(query[1], query[2], nums.size());
    }    
    return res;
}

int main() {
    vector<int> nums{1, 3, 4, 3, 4, 1, 34, 3, 2, 1, 2, 14, -45, 45, 5, 38, -987};
    //               0, 1, 2, 3, 4, 5,  6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16
    vector<vector<int>> queries{{0, 1,5}, {0, 12, 13}, {1, 15, 500}, {0, 15, 15}}; // 3, -45, -45
    for (auto x: findSumInRange(nums, queries)) cout<<x<<", ";
    cout<<endl;
}