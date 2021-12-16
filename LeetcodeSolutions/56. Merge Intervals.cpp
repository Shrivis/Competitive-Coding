class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end());
        for (int i=0; i<intervals.size(); ++i) {
            if(res.size()==0 || intervals[i][0] > res[res.size()-1][1])
                res.push_back(intervals[i]);
            else res[res.size()-1][1] = max(res[res.size()-1][1], intervals[i][1]);
        } 
        return res;
    }
};