
void dfs(int curr, vector<bool> &vis, stack<int> &st, vector<vector<int>> &adj) {
    vis[curr] = true;
    for (auto &node: adj[curr]) {
        if (!vis[node]) dfs(node, vis, st, adj);
    }
    st.push(curr);
}
void getTopologicalOrder(int n, vector<vector<int>>& edges) {
    vector<vector<int>> adj(n);
    vector<bool> vis(n, false);
    vector<int> topologicalOrder;
    for (auto edge: edges) {
        adj[edge[0]].push_back(edge[1]);
    }
    for (int i=0; i<n; ++i) {
        if (!vis[i]) {
            dfs(i, vis, topologicalOrder, adj);
        }
    }
    while(!st.empty()) {
        cout<<st.top()<<" ";
        st.pop();
    }
}