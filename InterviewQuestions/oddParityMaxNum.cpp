#include<bits/stdc++.h>

using namespace std;

class Solution {
    struct comp {
        bool operator()(vector<int> a, vector<int>b) {
            return a[0]>b[0];
        }
    };
public:
    int largestInteger(int num) {
        string dig = to_string(num);
        vector<vector<int>> Ehash;
        vector<vector<int>> Ohash;
        for (int i=0; i<dig.size(); ++i) {
            if (i&1) Ohash.push_back({(dig[i]-'0'), i});
            else Ehash.push_back({(dig[i]-'0'), i});
        }
        sort(Ehash.begin(), Ehash.end(), comp());
        sort(Ohash.begin(), Ohash.end(), comp());
        for (int i=0; i<dig.size(); ++i) {
            if (i&1) {
                if (dig[i]-'0' < Ohash[(i-1)/2][0]) {
                    swap(dig[i], dig[Ohash[(i-1)/2][1]]);
                }
            } else {
                if (dig[i]-'0' < Ehash[i/2][0]) {
                    swap(dig[i], dig[Ehash[i/2][1]]);
                }
            }
        }
        return stoi(dig);
    }
};

int main() {
    Solution* runner = new Solution();
    cout<<runner->largestInteger(500234);
    return 0;
}