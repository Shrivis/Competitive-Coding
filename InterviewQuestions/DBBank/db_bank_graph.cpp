#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define sz(A) (int)(A).size()
#define endl "\n"
#define pll pair<ll, ll>
#define pii pair<int, int>
#define all(m) m.begin(), m.end()
#define srch(A, b) A.find(b) != A.end()
#define vec(A) vector<A>
#define uset(A) unordered_set<A>
#define umap(A, B) unordered_map<A, B>
#define pq(A) priority_queue<A>
#define uid uniform_int_distribution
#define repp(i, B) for (int i = 0; i < B; ++i)
#define rep(i, A, B) for (int i = A; i < B; ++i)
#define rrep(i, A, B) for (int i = B; i >= A; --i)
#define fast                \
    cin.tie(0);             \
    cout.tie(0);            \
    cin.sync_with_stdio(0); \
    cout.sync_with_stdio(0);
using namespace std;
using str = string;
using ll = long long;
using ld = long double;

bool canReach(int node, int size) {
    if (node < 0 or node >= size) return false;
    return true;
}

void dfs(int curr, int cost, vec(vec(int)) adj, vec(int) & res) {
    if (res[curr] != -1 and res[curr] <= cost) return;
    res[curr] = cost;
    for (auto node : adj[curr]) {
        dfs(node, cost + 1, adj, res);
    }
}
vector<int> dijkstra(int V, vector<vector<int>> adj, int S) {
    vec(int) res(V, -1);
    dfs(S, 0, adj, res);
    return res;
}

vec(int) serverTimers(vec(int) & sendTime, int n) {
    vec(vec(int)) adj(n);
    repp(i, n-1) {
        if (canReach(i + sendTime[i], n)) {
            adj[i].pb(i + sendTime[i]);
            adj[i + sendTime[i]].pb(i);
        }
            
        if (canReach(i - sendTime[i], n)) {
            adj[i].pb(i - sendTime[i]);
            adj[i - sendTime[i]].pb(i);
        }
    }
    return dijkstra(n, adj, n-1);
}

int main() {
    int n;
    cin >> n;
    vec(int) sendTime(n);
    repp(i, n) cin >> sendTime[i];
    for (auto x : serverTimers(sendTime, n)) cout << x << " ";
    cout << endl;
}