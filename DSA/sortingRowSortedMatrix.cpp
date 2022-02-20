class Solution {
  public:
    vector<vector<int>> sortedMatrix(int N, vector<vector<int>> Mat) {
        vector<int> idxs(N, 0);
        vector<vector<int>> res(N, vector<int>(N, 0));
        int i=0;
        while(i<N*N) {
            int j=0, minIdx=-1, minVal=INT_MAX;
            while(j<idxs.size()) {
                if (minVal > Mat[j][idxs[j]] && idxs[j]<N) {
                    minIdx = j;
                    minVal = Mat[j][idxs[j]];
                }
                j++;
            }
            idxs[minIdx] += 1;
            res[i/N][i%N] = minVal;
            i++;
        }
        return res;
    }
};