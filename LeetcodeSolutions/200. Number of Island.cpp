class Solution {
    void islands(vector<vector<char>>& grid, int r, int c) {
        if (r<0 || r>=grid.size() || c<0 || c>=grid[0].size()) return;
        if (grid[r][c] == '0') return;
        grid[r][c] = '0';
        islands(grid, r-1, c);
        islands(grid, r, c-1);
        islands(grid, r+1, c);
        islands(grid, r, c+1);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int count=0;
        for (int r=0; r<grid.size(); ++r) {
            for (int c=0; c<grid[0].size(); ++c) {
                if (grid[r][c] == '1') {
                    count++;
                    islands(grid, r, c);
                }
            }
        }
        return count;
    }
};