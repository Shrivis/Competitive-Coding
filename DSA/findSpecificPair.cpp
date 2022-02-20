int findMaxValue(vector<vector<int>>& mat, int n) {
	vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    int maxDiff = INT_MIN;
    dp[0][0] = mat[0][0];
    for (int i=1; i<n; ++i) {
        dp[i][0] = min(mat[i][0], dp[i-1][0]);
        dp[0][i] = min(mat[0][i], dp[0][i-1]);
    }
    for (int i=1; i<n; ++i) {
        for (int j=1; j<n; ++j) {
            dp[i][j] = min(dp[i-1][j], min(dp[i][j-1], mat[i][j]));
			maxDiff = max(maxDiff, mat[i][j] - dp[i-1][j-1]);
        }
    }
	return maxDiff;
}