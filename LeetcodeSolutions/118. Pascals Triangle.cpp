class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pt;
        pt.push_back({1});
        if (numRows == 1) return pt;
        pt.push_back({1, 1});
        for (int i=1; i<numRows-1; ++i){
            vector<int> temp;
            temp.push_back(1);
            for (int j=0; j<pt[i].size()-1; ++j) {
                temp.push_back(pt[i][j]+pt[i][j+1]);
            }
            temp.push_back(1);
            pt.push_back(temp);
            temp.clear();
        }
        return pt;
    }
};

// Time O(n^2)