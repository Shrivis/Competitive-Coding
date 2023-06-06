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

str lex(str one, str two) {
    cout<<one<<" "<<two<<endl;
    repp(i, sz(one)) {
        if (one[i] > two[i]) return two;
        if (one[i] < two[i]) return one;
    }
    return one;
}
str beutifulSubSeq(str s, int n, int k, int x) {
    priority_queue<pair<char,int>> p;
    int b_count = 0, a_count = 0;
    repp(i, n) {
        if (s[i] == 'b') b_count++;
        if (s[i] == 'a') a_count++;
    }
    vec(bool) add(n, true);
    repp(i, k) {
        p.push({s[i], i});
    }
    rep(i, k, n) {
        cout<<p.top().ff<<p.top().ss<<endl;
        for (auto x: add) cout<<x<<" ";cout<<endl;
        if (s[i] < p.top().ff) {
            add[p.top().ss] = false;
            p.pop();
            p.push({s[i], i});
        } else {
            add[i] = false;
        }
    }
    str res = "";
    repp(i, n) {
        if (add[i]) res+=s[i];
    }
    return res;

}
int main() {
    fast
    str s = "aababb";
    cout<<beutifulSubSeq(s, sz(s), 4, 2)<<endl;
    return 0;
}