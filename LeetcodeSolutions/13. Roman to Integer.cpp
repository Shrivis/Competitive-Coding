class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> hash;
        hash['M'] = 1000;
        hash['D'] = 500;
        hash['C'] = 100;
        hash['L'] = 50;
        hash['X'] = 10;
        hash['V'] = 5;
        hash['I'] = 1;
        int idx=0;
        int i = 1, sum=0;
        for (int i=0; i<s.size()-1; ++i) {
            if (hash[s[i]] < hash[s[i+1]]) sum -= hash[s[i]];
            else sum += hash[s[i]];
        }
        sum += hash[s[s.size()-1]];
        return sum;
    }
};