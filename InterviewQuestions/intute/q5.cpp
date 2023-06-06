#include <bits/stdc++.h>
using namespace std;

int solve(int n, vector<vector<int>>& adj) {
    for (auto x: adj) cout<<x[0]<<":"<<x[1]<<endl;
    int ans = 0;
    vector<int> deg(n);
    for (auto& e : adj) deg[e[1]]++;
    for (int i = 0; i < n; ++i) {
        if (deg[i] == 0) ans++;
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;
        int a, b;
        for (int i = 0; i < m; ++i) {
            cin >> a >> b;
            adj.push_back({a - 1, b - 1});
        }
        cout <<"\nans: " <<solve(n, adj) << endl;
    }
    return 0;
}
