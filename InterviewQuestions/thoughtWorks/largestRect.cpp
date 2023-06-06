#include<bits/stdc++.h>
using namespace std;

int largestArea(int n, int m, vector<int> a, vector<int> b) {
    int end = 0, start = 0, i = 0, j = 0;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    while (i < n and j < m) {
        if (a[i] == b[j]) {
            if (start == 0)
                start = a[i];
            else
                end = a[i];
            i++;
            j++;
        }
        else if (a[i] > b[j])
            j++;
        else
            i++;
    }
    if (end == 0 or start == 0)
        return 0;
    else
        return (end - start);
}

int main() {
    cout<<largestArea(3, 2, {1,2,3}, {2,3});
    return 0;
}