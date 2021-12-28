class Solution {
    int maxArea(vector<vector<int>>& grid, int r, int c) {
        if (r<0 || r>=grid.size() || c<0 || c>=grid[0].size()) return 0;
        if (grid[r][c] == 0) return 0;
        grid[r][c] = 0;
        int size = 1;
        size += maxArea(grid, r-1, c);
        size += maxArea(grid, r, c-1);
        size += maxArea(grid, r+1, c);
        size += maxArea(grid, r, c+1);
        return size;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxSize=0;
        for (int r=0; r<grid.size(); ++r) {
            for (int c=0; c<grid[0].size(); ++c) {
                if (grid[r][c] == 1) maxSize = max(maxSize, maxArea(grid, r, c));
            }
        }
        return maxSize;
    }
};