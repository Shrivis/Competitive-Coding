class Solution {
public:
    int findMin(vector<int>& nums) {
        int lo=0, high=nums.size()-1, mid=0; 
        while(lo<high) {
            mid = lo + (high - lo)/2;
            if (nums[mid] > nums[nums.size()-1])
                lo = mid+1;
            else high = mid;
        }
        return nums[lo];
    }
};