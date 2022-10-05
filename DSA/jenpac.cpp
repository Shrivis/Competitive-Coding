#include <bits/stdc++.h>
using namespace std;

vector<int> solve(string s, int n) {
    vector<int> res(n);
    long long lo = 0, hi = n-1;
    for (int i=0; i<n; ++i) {
        if (s[i] == 'R') {
            res[lo] = i + 1;
            lo++;
        }
        else {
            res[hi] = i+1;
            hi--;
        }
    }
    return res;
}

int main() {
    string s = "LRRLLL";
    vector<int> res = solve(s, 6);
    for (auto x : res) cout << x << " ";
    cout << endl;
}