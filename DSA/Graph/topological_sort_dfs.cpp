#include <bits/stdc++.h>

using namespace std;

void dfs(int curr, vector<bool> &vis, stack<int> &st,
         vector<vector<int>> &adj) {
    vis[curr] = true;
    for (auto &node : adj[curr]) {
        if (!vis[node]) dfs(node, vis, st, adj);
    }
    st.push(curr);
}
void getTopologicalOrder(int n, vector<vector<int>> &edges) {
    vector<vector<int>> adj(n);
    vector<bool> vis(n, false);
    stack<int> topologicalOrder;
    for (auto edge : edges) {
        adj[edge[0]].push_back(edge[1]);
    }
    for (int i = 0; i < n; ++i) {
        if (!vis[i]) {
            dfs(i, vis, topologicalOrder, adj);
        }
    }
    while (!topologicalOrder.empty()) {
        cout << topologicalOrder.top() << " ";
        topologicalOrder.pop();
    }
}
int main() {
    vector<vector<int>> edges{{1, 0}, {0, 2}, {1, 2}, {0, 3}, {4, 2}};
    getTopologicalOrder(5, edges);
}