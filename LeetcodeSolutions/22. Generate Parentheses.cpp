class Solution {
    void backtrack(vector<string>& res, string s, int o, int c, int n) {
        if (n*2==s.size()) {
            res.push_back(s);
            return;
        }
        if (o<n) backtrack(res, s+"(", o+1, c,  n);
        if (c<o) backtrack(res, s+")", o, c+1, n);
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        backtrack(res, "", 0, 0, n);
        return res;
    }
};