#include <bits/stdc++.h>
using namespace std;

int solve(string s) {
    int n = s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for (int i = 1; i < n; ++i) {
        if (i <= r) {
            z[i] = min(r - i + 1, z[i - l]);
        }
        while (i + z[i] < n and s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    int sum = 0;
    for (auto x : z) {
        sum += x + 1;
    }
    return sum;
}
int main(void) {
    string s;
    cin >> s;
    cout << solve(s) << endl;
    return 0;
}