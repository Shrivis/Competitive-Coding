// int destroyTargets(vector<int>& nums, int space) {
//     map<int, int> hash;
//     set<int> res;
//     int max_val = -1, min_val = INT_MAX;
//     sort(nums.begin(), nums.end());
//     for (auto &num: nums) {
//         int curr = num/space;
//         curr = num - curr*space;
//         if (curr == 0) curr = space;
//         hash[curr]++;
//     }
//     for (auto i : hash) {
//         if (i.second > max_val) max_val = i.second;
//     }
//     for (auto i : hash) {
//         if (i.second == max_val) res.insert(i.first);
//     }
//     for (auto num: nums) {
//         int curr = num/space;
//         curr = num - curr * space;
//         if (curr == 0) curr = space;

//         if (res.find(x) != res.end()) {
//             if (min_val > num) min_val = num;
//         }
//     }
//     return min_val;
// }

#include <bits/stdc++.h>
using namespace std;

int GCD(int a, int b) {
    if (b == 0) return a;
    return GCD(b, a % b);
}

int main() {
    int n, q;
    cin>>n>>q;
    vector<int> nums(n), left(n), right(n);
    for (int i=0; i<n; ++i) cin>>nums[i];
    int res=0;
    while(q--) {
        int l, r;
        cin>>l>>r;
        res += GCD(nums[l], nums[r]);
    }
    cout<<res<<endl;
    return 0;
}

// #include <iostream>
// #include <vector>

// using namespace std;

// int gcd(int x, int y) {
//     int r = y % x;
//     while (r > 0) {
//         y = x;
//         x = r;
//         r = y % x;
//     }
//     return x;
// }

// int main() {
//     cin.sync_with_stdio(false);
//     int t;
//     cin >> t;
//     while (t--) {
//         int n, q;
//         cin >> n >> q;
//         vector<int> nums(n);

//         int i, j;
//         for (i = 0; i < n; i++) cin >> nums[i];
//         vector<int> fgcd(n);
//         vector<int> bgcd(n);
//         fgcd[0] = nums[0];
//         for (i = 1; i < n; i++) fgcd[i] = gcd(fgcd[i - 1], nums[i]);
//         bgcd[n - 1] = nums[n - 1];
//         for (i = n - 2; i >= 0; i--) bgcd[i] = gcd(bgcd[i + 1], nums[i]);

//         for (i = 0; i < q; i++) {
//             int l, r;
//             cin >> l >> r;
//             l--;
//             r--;
//             if (l == 0)
//                 cout << bgcd[r + 1];
//             else if (r == n - 1)
//                 cout << fgcd[l - 1];
//             else
//                 cout << gcd(fgcd[l - 1], bgcd[r + 1]);
//             cout << endl;
//         }
//     }
//     return 0;
// }