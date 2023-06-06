#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < n; ++i)
#define sz(a) (int)(a).size()
using namespace std;


int longestStr(string s, char rc, int k) {
    int len = 0, i = 0, j = 0;
    while (i < sz(s)) {
        if (s[i] != rc) {
            if (k > 0)
                k--;
            else {
                len = max(len, i - j);
                while (s[j] == rc) j++;
                j++;
            }
        }
        i++;
    }
    len = max(len, i - j);
    return len;
}

int main() {
    string s = "BBBBBBBBBBB";
    cout<<longestStr(s, 'A', 1)<<endl;
    return 0;
}