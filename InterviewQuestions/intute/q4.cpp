#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &arr) {
    int res = 0;
    for (int i = 0; i < n; i++) {
        int j = i, k = i;
        while (j >= 0 and v[j] == v[i] or v[j] == v[i] + 1) {
            j--;
        }
        while (k < n and v[k] == v[i] or v[k] == v[i] + 1) {
            k++;
        }
        res = max(res, k - j - 1);
    }
}

int main() {
    int t;
    cin>>t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (auto i = 0; i < n; i++) {
            cin>>arr[i];
        }
        cout<<solve(arr)<<endl;
    }
    return 0;
}