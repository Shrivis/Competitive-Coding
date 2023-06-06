#include<bits/stdc++.h>
using namespace std;

int stepTo0(int n) {
    vector<int> res(n+1, -1);
    queue<int> q;
    q.push(0);
    res[0] = 0;
    int step, curr;
    while (!q.empty()) {
        curr = q.front();
        step = res[curr] + 1;
        q.pop();
        if (res[curr + 1] == -1 && curr < n) {
            q.push(curr + 1);
            res[curr + 1] = step;
        }
        if (curr >= 2) {
            for (int i = 2; i <= curr && i * curr <= n; i++) {
                if (res[curr * i] == -1) {
                    q.push(curr * i);
                    res[curr * i] = step;
                }
            }
        }
    }
    return res[n];
}

// int downToZero(int n) {
//     vector<int> dp = helper(n);
//     return dp[n];
// }

int main() {
    int t;
    vector<int> res;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        res.push_back(stepTo0(n));
    }
    cout<<endl;
    for(auto x: res) cout<<x<<endl;
}