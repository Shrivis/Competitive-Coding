#include<iostream>
#include<vector>

using namespace std;

void spiralMatrix(vector<vector<int>> nums) {
    int top=0, bottom=nums.size();
    int left=0, right=nums[0].size();
    while (top<=bottom && left<=right) {
        for (int i=left; i<right; ++i) cout<<nums[top][i]<<" ";
        top++;
        for (int i=top; i<bottom; ++i) cout<<nums[i][right-1]<<" ";
        right--;
        if (top<=bottom) {
            for (int i=right-1; i>= left; --i) cout<<nums[bottom-1][i]<<" ";
            bottom--;
        }
        if (left<=right) {
            for (int i=bottom-1; i>=top; --i) cout<<nums[i][left]<<" ";
            left++;
        }
    }
    cout<<endl;
}

int main () {
    vector<vector<int>> nums{
        {1,  2,  3,  4},
        {5,  6,  7  ,8},
        {9, 10 ,11 ,12},
        {13,14, 15, 16},
    };
    spiralMatrix(nums);
    return 0;
}