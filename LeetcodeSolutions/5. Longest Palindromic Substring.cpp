class Solution {
    int palindrome(string s, int l, int r) {
        while (l >= 0 && r<s.size() && s.at(l) == s.at(r)) {
            l--;
            r++;
        }
        return r - l - 1;
    }
public:
    string longestPalindrome(string s) {
        if (s.size()<1) return "";
        int start=0, end=0, len=0;
        for (int i=0; i<s.size(); ++i) {
            int l1 = palindrome(s, i, i);
            int l2 = palindrome(s, i, i+1);
            len = max(l1, l2);
            if (len > end-start) {
                start = i - ((len -1) / 2);
                end = i + (len / 2);
            }
        }
        return s.substr(start, end-start+1);
    }
};