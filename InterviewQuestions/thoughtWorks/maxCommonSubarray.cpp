#include<bits/stdc++.h>
using namespace std;

int maxCommonSubarray(vector<int> &a, vector<int> &b) {
    int n=a.size(), m=b.size();
    int dp[n+1][m+1];
    for (int i=0; i<=n; ++i)
        for (int j=0; j<=m; ++j) dp[i][j] = 0;
    for (int i=n-1; i>=0; --i) {
        for (int j=m-1; j>=0; --j) {
            if (a[i] == b[j]) dp[i][j] = dp[i+1][j+1] + 1;
        }
    }
    int maxLen = 0;
    for (int i=0; i<n; ++i) {
        for (int j=0; j<m; ++j) {
            maxLen = max(maxLen, dp[i][j]);
        }
    }
    return maxLen;
}

int solve(int n, int m, vector<int> a, vector<int> b) {
    int x = maxCommonSubarray(a, b);
    return a.size() - x;
}

int main() {
    vector<int> a{1,1,2};
    vector<int> b{1,1};
    cout<<solve(3, 2, a, b)<<endl;
    return 0;
}