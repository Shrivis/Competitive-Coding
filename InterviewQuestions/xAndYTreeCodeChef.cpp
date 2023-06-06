#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define rep(i, x, n) for (int i=x; i<n; ++i)
#define rrep(i, x, n) for (int i=n; i>=x; --i)

int dfs(int curr, int pre, vector<int> &child_count, vector<vector<int>> &adj,
        vector<int> &parent) {
    int child = 1;
    parent[curr] = pre;
    for (auto node : adj[curr]) {
        if (node != pre) child += dfs(node, curr, child_count, adj, parent);
    }
    child_count[curr] = child - 1;
    return child;
}

void solve() {
    int n, res;
    cin >> n;
    res = n - 1;
    vector<vector<int>> adj(n + 1);
    vector<int> child_count(n + 1, 0);
    vector<int> child(n + 1, 0);
    vector<int> parent(n + 1, 0);
    vector<bool> vis(n + 1, false);
    int u, v;
    rep(i, n - 1) {
        cin >> u >> v;
        adj[v].pb(u);
        adj[u].pb(v);
    }
    dfs(1, 0, child_count, adj, parent);
    int q;
    cin >> q;
    while (q--) {
        int x;
        cin >> x;
        if (x == 1) {
            int node;
            cin >> node;
            if (child_count[node] == 0 and vis[node] == false) {
                vis[node] = true;
                child[node] = 1;
                res--;
                child[parent[node]] += child[node];
            } else {
                if (vis[node] == 0) {
                    if (child[node] == child_count[node]) {
                        res--;
                        vis[node] = 1;
                        child[node]++;
                        child[parent[node]] += child[node];
                    }
                }
            }
        } else {
            if (res == -1)
                cout << n - 1 << endl;
            else
                cout << res << endl;
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}