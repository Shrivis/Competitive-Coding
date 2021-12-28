class Solution {
    const int MOD = 1e9 + 7;
    int add(int a, int b){
        return ((a % MOD) + (b % MOD)) % MOD;
    }
public:
    int numTilings(int n) {
        vector<int> dp(n + 5);
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 5;
        for(int i = 4; i <= n; i++) dp[i] = add(2 * dp[i - 1], dp[i - 3]);
        return dp[n];
    }
};