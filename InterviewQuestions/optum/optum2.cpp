#include <bits/stdc++.h>
using namespace std;

int degreeCompliant(int input1, vector<string> input2) {
    int ans = 0;
    for (auto &it : input2) {
        int count = 0, sz = it.size();
        if (it[0] != '.' || it[1] != '-')
            for (int i = 0; i < it.size(); i++) {
                if (it[i] == '.')
                    count++;
                else {
                    if (count > 0) count--;
                }
            }
        ans += (count == 0);
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<string> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    cout << degreeCompliant(n, arr);

    return 0;
}