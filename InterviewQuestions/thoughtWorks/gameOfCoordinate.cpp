#include <bits/stdc++.h>
using namespace std;

// bool isPossibel(long long x, long long y) {
//     if (x < 1 or y < 1) return false;
//     if (x == 1 and y == 1) return true;
//     return isPossibel(x - y, y) or isPossibel(x, y - x);
// }
// string solve(long long y, long long x) {
//     if (isPossibel(x, y)) return "Yes";
//     return "No";
// }

long long GCD(long long a, long long b) {
    if (b == 0) return a;
    return GCD(b, a % b);
}

string solve(long long x, long long y) {
    int val = GCD(x, y);
    if ((val & (val - 1)) == 0) cout << "Yes";
    else cout << "No";
}

int main() {
    cout << solve(1, 2) << endl;
    cout << solve(2, 3) << endl;
    cout << solve(4, 6) << endl;
    return 0;
}