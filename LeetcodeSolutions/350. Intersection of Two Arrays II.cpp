class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int idx=0, idx1=0, idx2=0, i=0;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        while(idx1 < nums1.size() && idx2<nums2.size()) {
            if (nums1[idx1] == nums2[idx2]) {
                nums1[idx] = nums1[idx1];
                idx++;
                idx1++;
                idx2++;
            }
            else if (nums1[idx1] > nums2[idx2]) idx2++;
            else idx1++;
            i++;
        }
        nums1.resize(idx);
        return nums1;
    }
};

// Time O(n)
// Space O(1)