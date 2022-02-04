class Trie {
public:
    bool end;
    vector<Trie*> nexts;
    Trie() {
        end = false;
        nexts.resize(26, NULL);
    }
    
    void insert(string word) {
        Trie* itr = this;
        for (char n: word) {
            if (itr->nexts[n-'a'] == NULL)
                itr->nexts[n-'a'] = new Trie();
            itr = itr->nexts[n-'a'];
        }
        itr->end = true;
    }
    
    bool search(string word) {
        Trie* itr = this;
        for (char n: word) {
            if (itr->nexts[n-'a'] == NULL)
                return false;
            itr = itr->nexts[n-'a'];
        }
        return itr->end;
    }
    
    bool startsWith(string prefix) {
        Trie* itr = this;
        for (char p: prefix) {
            if (itr->nexts[p-'a'] == NULL)
                return false;
            itr = itr->nexts[p-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */