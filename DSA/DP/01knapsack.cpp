vector<vector<int>> t(n+1, vector<int>(w+1, -1));
int knapsack(vector<int> wt, vector<int> val. int w, int n) {
    if (n==0 || w==0) return 0;
    if (t[n][w] != -1) return t[n][w];
    if (wt[n-1] <= w)
        return t[n][w] = max(val[n-1]+knapsack(wt, val, w-wt[n-1], n-1));
    else
        return t[n][w] = knapsack(wt, val, W, n-1);
}