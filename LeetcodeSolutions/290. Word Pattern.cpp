class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> hash;
        unordered_set<string> set;
        int count=0, idx=0;
        int i = -1;
        while(++i <= s.size()) {
            if (s[i] != ' ') count++;
            else {
                string word = s.substr(i-count, count);
                if (hash.find(pattern[idx]) != hash.end()) {
                    if (hash[pattern[idx]] != word) return false;
                } else {
                    hash[pattern[idx]] = word;
                }
                count = 0;
                idx++;
            }
        }
        string word = s.substr(i-count, count);
        if (hash.find(pattern[idx]) != hash.end()) {
            if (hash[pattern[idx]] != word) return false;
        } else {
            hash[pattern[idx]] = word;
        }
        for (auto &n: hash) {
            if (set.count(n.second)) return false;
            else (set.insert(n.second));
        }
        if (idx!=pattern.size()-1) return false;
        return true;
    }
};