#include <bits/stdc++.h>

using namespace std;

void getTopologicalOrder(int n, vector<vector<int>>& edges) {
    vector<vector<int>> adj(n);
    vector<bool> vis(n, false);
    vector<int> indegree(n);
    queue<int> q;
    vector<int> topologicalOrder;
    for (auto edge: edges) {
        adj[edge[0]].push_back(edge[1]);
    }
    for (auto nodes: adj) {
        for (auto node: nodes) {
            indegree[node]++;
        }
    }
    for (int i=0; i<n; ++i) {
        if (indegree[i] == 0) q.push(i);
    }
    while(!q.empty()) {
        int curr = q.front(); q.pop();
        vis[curr] = true;
        topologicalOrder.push_back(curr);
        for (auto node: adj[curr]) {
            indegree[node]--;
            if(!vis[node] and indegree[node] == 0) q.push(node);
        }
    }
    for (auto node : topologicalOrder) {
        cout<<node<<" ";
    }
    cout<<endl;
}
int main() {
    vector<vector<int>> edges{{1, 0}, {0, 2}, {1, 2}, {0, 3}, {4, 2}};
    getTopologicalOrder(5, edges);
}