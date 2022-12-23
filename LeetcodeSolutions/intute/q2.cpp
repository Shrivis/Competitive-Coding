
#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> arr) {
    int ans = 1;
    if (arr.size() == 0) return 0;
    for (int i = 0; i < arr.size() - 1; ++i) {
        int temp = arr[i], count = 1;
        for (int j = i + 1; j < arr.size(); ++j) {
            if (arr[j] == temp or arr[j] == temp + 1)
                count++;
            else
                break;
        }
        ans = max(ans, count);
    }
    return ans;
}

int main() {
    int t;
    vector<int> res;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> nums(N);
        for (int i = 0; i < N; ++i) {
            cin >> nums[i];
        }
        cout<<solve(nums)<<endl;
    }
    return 0;
}
