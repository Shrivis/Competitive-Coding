#include<bits/stdc++.h>
using namespace std;

vector<int> findMinInRange(vector<int> &nums, vector<pair<int,int>> queries) {
    int n = nums.size();
    vector<int> res;
    vector<vector<int>> stable(n, vector<int>(log2(n)+1, 0));

    // precomputation
    for (int i=0; i<n; ++i) stable[i][0] = nums[i];
    for (int j=1; j<log2(n)+1; ++j) {
        for (int i=0; i+(1<<j)-1<n; ++i) {
            stable[i][j] = min(stable[i][j-1], stable[i+(1<<(j-1))][j-1]);
        }
    }
    for (auto x: queries) {
        int len = x.second-x.first+1;
        int k = 31 - __builtin_clz(len); // use log[i] = log[i/2]+1;
        res.push_back(min(stable[x.first][k], stable[x.second-(1<<k)+1][k]));
    }
    return res;
}

int main() {
    vector<int> nums{4, 3, 53, 23, 4, 45, 34, 3, 2, 1, 544, 4, -45, 45, 5, 38, -987};
    //               0, 1, 2,  3,  4, 5,  6,  7, 8, 9, 10,  11, 12, 13, 14, 15, 16
    vector<pair<int, int>> queries{{1,5}, {4, 13}, {0, 15}, {0, 16}}; // 3, -45, -45
    for (auto x: findMinInRange(nums, queries)) cout<<x<<", ";
    cout<<endl;
}