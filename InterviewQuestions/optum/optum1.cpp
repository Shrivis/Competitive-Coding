
#include <bits/stdc++.h>
using namespace std;
vector<int> solve(vector<int> &nums, int n) {
    set<int> s;
    vector<int> res(n);
    for (int i = n - 1; i >= 0; i--) {
        s.insert(nums[i]);
        auto it = s.lower_bound(nums[i]);
        res[i] = distance(s.begin(), it);
    }
    return res;
}

int main() {
    vector<int> nums{12, 1, 2, 3, 0, 11, 4};
    vector<int> res = solve(nums, nums.size());
    for (auto x:)
    return 0;
}