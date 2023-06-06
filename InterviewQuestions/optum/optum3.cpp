#include <bits/stdc++.h>
using namespace std;

int solve(int n) {
    if (n == 1) return 0;
    n = n - 1;
    int res = 1, s = 0;
    while (n > 1) {
        ++s;
        res += (n & 1) << s;
        n >>= 1;
    }
    return res;
}

int main() {
    cout << solve(1);
    return 0;
}