class Solution {
public:
    void sortColors(vector<int>& nums) {
        int bIdx = 0, wIdx=0;
        int n = nums.size();
        if (n<2) return;
        for (int i=0; i<n; i++) {
            if (nums[i] == 0) {
                nums[i] = nums[wIdx]; 
                nums[wIdx] = nums[bIdx];
                nums[bIdx] = 0;
                bIdx++;
                wIdx++;
            }
            else if (nums[i] == 1) {
                nums[i] = nums[wIdx];
                nums[wIdx] = 1;
                wIdx++;
            }
        }
    }
};