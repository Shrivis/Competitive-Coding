#include<iostream>
#include<vector>

using namespace std;

vector<int> merge(vector<int> nums1, vector<int> nums2) {
    int i=0, j=0, k=0;
    vector<int> res;
    while(i<nums1.size() && j<nums2.size()) {
        if (nums1[i] < nums2[j]) res.push_back(nums1[i++]);
        else res.push_back(nums2[j++]);
    }
    while(i<nums1.size()) res.push_back(nums1[i++]);
    while(j<nums2.size()) res.push_back(nums2[j++]);
    return res;
}

vector<int> mergeSort(vector<int> &nums, int lo, int hi) {
    if (lo == hi)  return {nums[lo]};
    int mid = lo + (hi-lo)/2;
    return merge(mergeSort(nums, lo, mid), mergeSort(nums, mid+1, hi));
}

// driver code
int main() {
    vector<int> nums {1,3,4,2,8,-7};
    vector<int> res;
    res = mergeSort(nums, 0, nums.size()-1);
    for(int num: res) cout<<num<<" ";cout<<endl;
    return 0;
}

// O(log(n)) time complexity
// O(1) space complexity