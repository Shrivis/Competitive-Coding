#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    class Trie {
    public:
        bool end;
        vector<Trie*> nexts;
        Trie() {
            end = false;
            nexts.resize(26, NULL);
        }
        void insertUtil(vector<vector<char>>& board, int i, int j, vector<vector<bool>>& v, Trie* curr) {
            if (i-1>=0 and !v[i-1][j]) {
                v[i-1][j] = true;
                if (curr->nexts[board[i-1][j]-'a'] == NULL) 
                        curr->nexts[board[i-1][j]-'a'] = new Trie();
                insertUtil(board, i-1, j, v, curr->nexts[board[i-1][j]-'a']);
                v[i-1][j] = false;
                // is_over = false;
            } 
            // down
            if (i+1<board.size() and !v[i+1][j]) {
                v[i+1][j] = true;
                if (curr->nexts[board[i+1][j]-'a'] == NULL) 
                        curr->nexts[board[i+1][j]-'a'] = new Trie();
                insertUtil(board, i+1, j, v, curr->nexts[board[i+1][j]-'a']);
                v[i+1][j] = false;
                // is_over = false;
            }
            // right
            if (j+1<board[0].size() and !v[i][j+1]) {
                v[i][j+1] = true;
                if (curr->nexts[board[i][j+1]-'a'] == NULL) 
                        curr->nexts[board[i][j+1]-'a'] = new Trie();
                insertUtil(board, i, j+1, v, curr->nexts[board[i][j+1]-'a']);
                v[i][j+1] = false;
                // is_over = false;
            }
            // left
            if (j-1>=0 and !v[i][j-1]) {
                v[i][j-1] = true;
                if (curr->nexts[board[i][j-1]-'a'] == NULL) 
                        curr->nexts[board[i][j-1]-'a'] = new Trie();
                insertUtil(board, i, j-1, v, curr->nexts[board[i][j-1]-'a']);
                v[i][j-1] = false;
                // is_over = false;
            }
            // if (is_over) curr->end = true;
            return;
        }
        void insert(vector<vector<char>>& board) {
            Trie* itr = this;
            vector<vector<bool>> v(board.size(), vector<bool>(board[0].size(), false));
            for (int i=0; i<board.size(); ++i) {
                for (int j=0; j<board[0].size(); ++j) {
                    v[i][j] = true;
                    if (itr->nexts[board[i][j]-'a'] == NULL) 
                        itr->nexts[board[i][j]-'a'] = new Trie();
                    insertUtil(board, i, j, v, itr->nexts[board[i][j]-'a']);
                    v[i][j] = false;
                }
            }
            // Trie* itr = this;
            // for (char n: word) {
            //     if (itr->nexts[n-'a'] == NULL)
            //         itr->nexts[n-'a'] = new Trie();
            //     itr = itr->nexts[n-'a'];
            // }
            // itr->end = true;
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

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        Trie* t = new Trie();
        t->insert(board);
        for (auto word: words) {
            if (t->startsWith(word)) res.emplace_back(word);
        }
        return res;
    }
};

int main () {
    vector<vector<char>> board
    {
        {'a','a','a','a','a','a','a','a','a','a','a','a'},
        {'a','a','a','a','a','a','a','a','a','a','a','a'},
        {'a','a','a','a','a','a','a','a','a','a','a','a'},
        {'a','a','a','a','a','a','a','a','a','a','a','a'},
        {'a','a','a','a','a','a','a','a','a','a','a','a'},
        {'a','a','a','a','a','a','a','a','a','a','a','a'},
        {'a','a','a','a','a','a','a','a','a','a','a','a'},
        {'a','a','a','a','a','a','a','a','a','a','a','a'},
        {'a','a','a','a','a','a','a','a','a','a','a','a'},
        {'a','a','a','a','a','a','a','a','a','a','a','a'},
        {'a','a','a','a','a','a','a','a','a','a','a','a'},
        {'a','a','a','a','a','a','a','a','a','a','a','a'}
    };
    vector<string> words{"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};
    Solution* runner = new Solution();
    for (auto word: runner->findWords(board, words)) cout<<word<<endl;
    return 0;
}