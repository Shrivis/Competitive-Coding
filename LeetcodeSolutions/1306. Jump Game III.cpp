class Solution {
public:
        bool assist(vector<bool> &seen, vector<int> &arr, int idx) {
            if (idx < 0 || idx >= arr.size() || seen[idx])
                return false;
            if(arr[idx] == 0) return true;
            seen[idx] = true;
            return assist(seen, arr, idx - arr[idx]) || assist(seen, arr, idx + arr[idx]);
        }
        bool canReach(vector<int> &arr, int start) {
            vector<bool> seen(arr.size());
            return assist(seen, arr, start);
        }
};