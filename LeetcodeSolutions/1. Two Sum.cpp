class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> _map;
        for(int i=0; i<nums.size(); i++) {
            int num = nums[i];
            int find = target - num;
            auto it = _map.find(find);
            if (it !=  _map.end()) {
                return {it->second, i};
            }
            else {
                _map[num] = i;
            }
        }
        return {};
    }
};