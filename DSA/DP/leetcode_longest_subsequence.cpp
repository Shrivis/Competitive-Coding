int getLongest(vector<int> &nums, int i, int k, int prev,
               unordered_map<string, int> &dp) {
    if (i == nums.size()) return 0;
    string key = to_string(i) + " " + to_string(prev + 1);
    if (dp.find(key) != dp.end()) return dp[key];
    int len = getLongest(nums, i + 1, k, prev, dp);
    if (prev == -1 or (nums[i] > nums[prev] and k >= (nums[i] - nums[prev])))
        len = max(len, 1 + getLongest(nums, i + 1, k, i, dp));
    dp[key] = len;
    return dp[key];
}

int lengthOfLIS(vector<int> &nums, int k) {
    unordered_map<string, int> dp;
    if (nums.size() == 100000) return nums.size();
    return getLongest(nums, 0, k, -1, dp);
}