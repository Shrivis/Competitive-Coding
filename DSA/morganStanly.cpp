#include <bits/stdc++.h>
using namespace std;

bool solve(int x, int y, int x1, int y1) {
    if (x > x1 or y > y1) return false;
    if (x == x1 and y == y1) return true;
    bool l = solve(x, x + y, x1, y1);
    bool r = solve(x + y, y, x1, y1);
    return l or r;
}

int main() {
    int x = 1, y = 4, x1 = 5, y1 = 9;
    cout << solve(x, y, x1, y1)<<endl;
    return 0;
}