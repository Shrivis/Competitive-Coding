class Solution {
public:
    void rev(string &subStr, int s, int e) {
        for (int i=s; i<(s+e+1)/2; ++i) {
            swap(subStr[i], subStr[e+s-i]);
        }
    }
    string reverseWords(string s) {
        int idx=0;
        int n = s.size();
        for (int i=0; i<n; ++i) {
            if (s[i] == ' ') {
                rev(s, idx, i-1);
                idx = i+1;
            }
        }
        rev(s, idx, n-1);
        return s;
    }
};