class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<bool> vis(numCourses, false);
        vector<int> indegree(numCourses);
        queue<int> q;
        int count = 0;
        for (auto edge: prerequisites) {
            adj[edge[0]].push_back(edge[1]);
        }
        for (auto nodes: adj) {
            for (auto node: nodes) {
                indegree[node]++;
            }
        }
        for (int i=0; i<numCourses; ++i) {
            if (indegree[i] == 0) q.push(i);
        }
        while(!q.empty()) {
            int curr = q.front(); q.pop();
            vis[curr] = true;
            count++;
            for (auto node: adj[curr]) {
                indegree[node]--;
                if(!vis[node] and indegree[node] == 0) q.push(node);
            }
        }
        return (count==numCourses);
    }
};