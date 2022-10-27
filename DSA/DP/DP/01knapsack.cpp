#include<vector>
using namespace std;
int n=10, W=12;

vector<vector<int>> t(n+1, vector<int>(W+1, -1));
int knapsack(vector<int> wt, vector<int> val, int W, int n) {
    if (n==0 || W==0) return 0;
    if (t[n][W] != -1) return t[n][W];
    if (wt[n-1] <= W)
        return t[n][W] = max(val[n-1]+knapsack(wt, val, W-wt[n-1], n-1), knapsack(wt, val, W, n-1));
    else
        return t[n][W] = knapsack(wt, val, W, n-1);
}


