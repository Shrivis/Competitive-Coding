class Solution {
public:
    string countAndSay(int n) {
        if (n==1) return "1";
        string s = countAndSay(n-1);
        string res;
        int count = 0;
        char prev = s[0];
        for (auto curr:s) {
            if (prev == curr) count++;
            else {
                res += to_string(count) + prev;
                prev = curr;
                count = 1;
            }
        }
        res += to_string(count) + s[s.size()-1];
        return res;
    }
};