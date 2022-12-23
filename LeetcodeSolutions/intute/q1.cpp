
#include <bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> arr, vector<vector<int>> Q, int M) {
    vector<int> res;
    unordered_map<int, int> hash;
    for (auto x: arr) hash[x%M]++;
    for (auto q : Q) {
        if (q[0] == 2) {
            res.push_back(hash[q[1]]);
        } else {
            hash[arr[q[1]-1]%M]--;
            arr[q[1] - 1] = q[2];
            hash[q[2]%M]++;
        }
    }
    return res;
}

int main() {
    int N, M;
    cin>>N>>M;
    vector<int> arr(N);
    vector<vector<int>> Q;

    for (int i=0; i<N; ++i) {
        cin>>arr[i];
    }
    
    int q_size;
    cin>>q_size;
    for (int i=0; i<q_size; ++i) {
        int a, b, c;
        cin>>a;
        if (a == 1)  {
            cin>>b>>c;
            Q.push_back({a,b,c});
        }else {
            cin>>b;
            Q.push_back({a, b});
        }
    }



    for (auto x : solve(arr, Q, M)) {
        cout << x << endl;
    }
    return 0;
}
