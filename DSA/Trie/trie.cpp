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
};