class Storage {
   public:
    bool visited;
    bool is_ans;
    int disc;
    int low;
    Storage() : visited(false), is_ans(false), disc(0), low(0) {}
};
vector<Storage*> node;
void dfs(vector<int> adj[], int u, int d, int parent) {
    node[u]->visited = true;
    node[u]->low = d;
    node[u]->disc = d;
    int count = 0;
    for (auto v : adj[u]) {
        if (parent == v)
            continue;
        else if (node[v]->visited == true)
            node[u]->low = min(node[u]->low, node[v]->disc);
        else {
            count++;
            dfs(adj, v, ++d, u);
            node[u]->low = min(node[u]->low, node[v]->low);
            if (parent == -1) {
                if (count >= 2) node[u]->is_ans = true;
            } else {
                if (node[v]->low >= node[u]->disc) node[u]->is_ans = true;
            }
        }
    }
}
vector<int> articulationPoints(int V, vector<int> adj[]) {
    node.resize(V);
    for (int i = 0; i < V; ++i) node[i] = new Storage();
    dfs(adj, 0, 0, -1);
    vector<int> ans;
    for (int i = 0; i < V; ++i)
        if (node[i]->is_ans == true) ans.push_back(i);
    if (ans.size() == 0) return {-1};
    return ans;
}