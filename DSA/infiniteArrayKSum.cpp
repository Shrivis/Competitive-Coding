#include <bits/stdc++.h>
using namespace std;

long solve(vector<int> &nums, int K) {
    long long totalSum = 0;
    for (auto x: nums) sum += x;
    if (tatalSum >= K) return solveUsingSlidingWindow(nums, K);
    else {
        long long res = ;
        return K / totalSum + findSumAtEnds(nums, K%totalSum);
    }
}

int main() {
    vector<int> nums{3,7,2,1,2};
    cout<<solve(nums, 5);
}