class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string> uSet;
        for (int i=0; i<9; ++i) {
            for (int j=0; j<9; ++j) {
                if (board[i][j] != '.'){
                    char val = board[i][j];
                    if (
                        !uSet.insert(to_string(val) + "r" + to_string(i)).second ||
                        !uSet.insert(to_string(val) + "c" + to_string(j)).second ||
                        !uSet.insert(to_string(val)  + "b" + to_string(i/3) + "-" + to_string(j/3)).second
                    ) return false;
                }
            }
        }
        return true;
    }
};