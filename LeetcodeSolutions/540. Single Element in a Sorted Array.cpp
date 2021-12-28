class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        else if ( nums[0] != nums[1]) return nums[0];
        else if (nums[n - 1 ] != nums[n - 2]) return nums[n - 1];
        else return binSer (nums, 0, n-1);
    }
    
    int binSer(vector<int>& nums, int a, int b ) {
        int mid = (a + b) / 2;
        if (nums[mid] != nums[mid+1] && nums[mid] != nums[mid-1] ) return nums[mid];
        if ( mid%2 != 0 && nums[mid-1] == nums[mid] || mid%2==0 && nums[mid] == nums[mid+1])
            return binSer(nums, mid+1, b);
        return binSer(nums, a, mid-1);
    }
};

// Approach: Modified Binary Search
// Time Complexity: O(logn)
