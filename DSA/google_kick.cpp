#include <bits/stdc++.h>
using namespace std;

long long getId(vector<long long> &nums, long long x) {
    int lo = 0, hi = nums.size() - 1;
    long long ans = 0;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (nums[mid] <= x) {
            ans = mid;
            lo = mid + 1;
        } else
            hi = mid - 1;
    }
    return ans;
}
long long result(int n, vector<long long int> arr) {
    long long r = -1;
    for (int i = arr.size() - 1; i > 0; i--) {
        if (arr[i] <= n * 2) {
            r = arr[i];
            break;
        }
    }
    return r;
}
void solve() {
    long long n;
    cin >> n;
    vector<long long> data(n), s_data, res;
    for (int i = 0; i < n; ++i) {
        cin >> data[i];
    }
    s_data = data;
    for (int i = 0; i < n; ++i) {
        s_data = data;
        swap(s_data[0], s_data[i]);
        sort(s_data.begin() + 1, s_data.end());
        res.push_back(result(s_data[0], s_data));
    }
    for (auto c : res) cout << c << " ";
    return;
}
int main() {
    int n;
    cin >> n;
    for (int i = 1; i < n + 1; ++i) {
        cout << "Case #" << i << ":";
        solve();
        cout << endl;
    }
    return 0;
}