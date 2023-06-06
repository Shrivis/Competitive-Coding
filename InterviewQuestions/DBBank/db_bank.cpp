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

bool canReach(int pos, int n) {
    cout<<pos<<" "<<n;
    if (pos<0 or pos > n) return false;
    return true;
}


vec(int) serverTimers(vec(int) & sendTime, int n) {
    vec(int) res(n, -1);
    queue<int> q;
    rep(i, 1, n + 1) {
        int seconds = 0;
        q.push(i);
        vec(bool) seen(n+1, false);         
        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                int curr = q.front(); q.pop();
                seen[curr] = true;
                if (curr == n) {
                    res[i-1] = seconds;
                    q = {};
                    break;
                }
                int op1 = curr + sendTime[curr - 1];
                int op2 = curr - sendTime[curr - 1];
                if (canReach(op1, n) and !seen[op1]) 
                    q.push(curr + sendTime[curr - 1]);
                if (canReach(op2, n) and !seen[op2])
                    q.push(curr - sendTime[curr - 1]);
            }
            seconds++;
        }
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    vec(int) sendTime(n);
    repp(i, n) cin >> sendTime[i];
    for (auto x : serverTimers(sendTime, n)) cout << x << " ";
    cout << endl;
}