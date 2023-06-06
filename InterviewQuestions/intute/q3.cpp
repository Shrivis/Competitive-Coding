
#include <bits/stdc++.h>
using namespace std;

long long solve(vector<int> arr, int M, int G) {
    long long count = 0;
    for (auto x: arr) {
        if (x<=M and x%G == 0) count++;
    }
    return count;
}

int main() {
    int t;
    vector<int> res;
    cin >> t;
    while (t--) {
        int N, M, G;
        cin >> N>>M>>G;
        vector<int> arr(N);
        for (int i = 0; i < N; ++i) {
            cin >> arr[i];
        }
        res.push_back(solve(arr, M, G));
    }
    for (auto x : res) cout << x << endl;
    return 0;
}
