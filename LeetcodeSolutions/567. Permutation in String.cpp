class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> sub(26, 0);
        vector<int> match(26, 0);
        if (s1.size()>s2.size()) return false;
        bool res = false;
        for (char c: s1) sub[c-'a']++;
        int i=0, j=s1.size()-1;
        for (int x=0; x<=j; ++x) match[s2[x]-'a']++;
        while(j<s2.size()-1) {
            if (match == sub) return true;
            match[s2[i]-'a']--;
            match[s2[++j]-'a']++;
            i++;
        }
        return (sub == match);
    }
};