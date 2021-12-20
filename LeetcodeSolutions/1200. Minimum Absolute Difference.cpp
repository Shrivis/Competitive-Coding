class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int minDiff=INT_MAX;
        sort(arr.begin(), arr.end());
        vector<vector<int>> res;
        for (int i=0; i<arr.size()-1; ++i) {
            int diff = abs(arr[i] - arr[i+1]);
            if (diff < minDiff) {
                res.clear();
                minDiff=diff;
            }
            if (diff == minDiff) res.push_back({arr[i],arr[i+1]});
        }
        
    return res;
    }
};