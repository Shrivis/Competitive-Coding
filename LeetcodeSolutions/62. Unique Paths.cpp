class Solution {
    // int girdTraveller(int m, int n, unordered_map<string, int>& hash) {
    //     string key = to_string(m) +"," + to_string(n);
    //     if (hash.find(key) != hash.end()) return hash[key];
    //     else if (m==0||n==0) return 0;
    //     else if (m==1&&n==1) return 1;
    //     else {
    //         hash[key] = girdTraveller(m-1, n, hash) + girdTraveller(m, n-1, hash);
    //         return hash[key];    
    //     }        
    // }
public:
    int uniquePaths(int m, int n) {
        // unordered_map<string, int> hash;
        // int res = girdTraveller(m, n, hash);
        // return res;
        vector<vector<int>> dp(m, vector<int>(n, 0));  
        for (int i=0; i<n; ++i) dp[0][i] = 1;
        for (int i=0; i<m; ++i) dp[i][0] = 1;        
        for (int i=1; i<m; ++i) {
            for (int j=1; j<n; ++j) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }        
        return dp[m-1][n-1];
    }
};