#include<bits/stdc++.h>
using namespace std;

bool canAchieve(int K, string S, string T) {
    if (S.size() != T.size()) return false;
    int bias, n;
    n = S.size();
    for (int i=0; i<n; ++i) {
        if (S[i] != T[i]) {
        bias = (int(T[i]-S[i])+26)%26;
        if (bias > K) return false;
        }
    }
    return true;
}

int main() {
    cout<<canAchieve(3, "abc", "edd");
    return 0;
}

