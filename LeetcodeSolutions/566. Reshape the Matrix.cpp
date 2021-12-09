class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int n = mat.size();
        int m = mat[0].size();
        int idx=0;
        if (m*n != r*c) return mat;
        vector<vector<int>> res (r, vector<int>(c));
        for (int i=0; i<n; ++i) {
            for (int j=0; j<m; ++j) {
                res[idx/c][idx%c] = mat[i][j];
                idx++;
            }
        }
        return res;
    } 
};

// time O(n^2)
// space O(n^2)