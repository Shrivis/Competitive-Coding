class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res=nums[0], all=1;
        for (int i=0; i<nums.size(); ++i) {
            all *= nums[i];
            res = max(res, all);
            if (all == 0) all = 1;
        }
        all = 1;
        for (int i=nums.size()-1; i>=0; --i) {
            all *= nums[i];
            res = max(res, all);
            if (all == 0) all = 1;
        }
        return res;
    }
};