#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &heights, int n) {
    stack<int> s;
    vector<int> res;
    for (int i = 0; i < n; i++) {
        while (!s.empty() and s.top() >= heights[i]) s.pop();
        if (s.empty()) res.push_back(-1);
        else res.push_back(s.top());
        s.push(heights[i]);
    }
    if (res.size() == 0) cout << "No person found";
    for (auto x : res) cout << x << " ";
}
int main() {
    vector<int> nums{1, 2, 3, 4, 5};
    solve(nums, 5);
    cout << endl;
    return 0;
}