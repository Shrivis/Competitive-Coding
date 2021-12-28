class Solution {
public:
    int maxPower(string s) {
        int count=1, res=1;
        if (s.size()<2) return 1;
        for (int i=0; i<s.size()-1; ++i) {
            if (s[i] == s[i+1]) count++;
            else {
                res = max(res, count);
                count=1;
            }
        }
        return max(res, count);
    }
};