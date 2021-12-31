class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int lo=0, high=nums.size()-1, mid;
        vector<int>res(2,-1);
        if (high<0) return res;
        while(lo<=high) {
            mid = lo + (high-lo)/2;
            if (nums[mid] >= target) high = mid-1;
            else lo = mid+1;
            if (nums[mid] == target) res[0] = mid;
        }
        lo=max(res[0], 0); high=nums.size()-1;
        while(lo <= high) {
        mid = lo + (high-lo)/2;
            if (nums[mid] <= target) lo = mid + 1;
            else high = mid-1;
            if (nums[mid] == target) res[1] = mid;
        }
        
        return res;
    }
};