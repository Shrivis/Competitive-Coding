int withoutZero(vector<int> &arr, int n, int sum) {
    vector<vector<int>> t(n+1, vector<int>(sum+1, 0));
    for (int i=0; i<n+1; ++i) t[i][0] = 1;
    for (int i=1; i<n+1; ++i) {
        for (int j=1; j<sum+1; ++j) {
            if (arr[i-1] <= j)
                t[i][j] = (t[i-1][j-arr[i-1]] + t[i-1][j])%((int)pow(10,9)+7);
            else
                t[i][j] = (t[i-1][j])%((int)pow(10,9)+7);
        }
    }
    return t[n][sum];
}
public:
int perfectSum(int arr[], int n, int sum) {
    vector<int> nums;
    for (int i=0; i<n; i++) {
        if (arr[i]>0) nums.push_back(arr[i]);
    }
    int zero = n-nums.size();
    int res = withoutZero(nums, n-zero, sum);
    return res*(int)pow(2, zero)%((int)pow(10,9)+7);
}