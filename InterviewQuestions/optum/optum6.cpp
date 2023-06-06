#include <bits/stdc++.h>
using namespace std;

int fun(int n, int k) {
    if (n == 1 or k == 1 or k == 0) return k;
    int curr_try, res = INT_MAX;
    for (int i = 1; i <= k; ++i) {
        curr_try = max(fun(n - 1, i - 1), fun(n, k - i));
        res = min(curr_try, res);
    }
    return res+1;
}

int main() {
    cout<<fun(2, 10)<<endl;
    return 0;
}