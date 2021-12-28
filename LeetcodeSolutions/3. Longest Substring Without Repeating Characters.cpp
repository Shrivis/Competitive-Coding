class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> map(256, -1);
        int idx = 0, i = 0;
        int n = s.size();
        int res = 0;
        while(i<n) {
            if(map[s[i]] != -1)
                idx = max(map[s[i]]+1, idx);
            map[s[i]] = i;
            res = max(res, i-idx+1);
            i++;
        }
        return res;
    }
};