class Solution {
    void helper(int num, int low, int high, vector<int> &res) {
        if (num >= low && num <= high) res.push_back(num);
        if (num > high) return;
        int x = num%10;
        if (x!=0 && x<9) {
            num = num*10 + (x+1);
            helper(num, low, high, res);
        }
    }
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> res;
        for (int i=1; i<10; ++i) {
            helper(i, low, high, res);
        }
        sort(res.begin(), res.end());
        return res;
    }
};