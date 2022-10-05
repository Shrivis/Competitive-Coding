#include <bits/stdc++.h>
using namespace std;
int solve(string s1, string s2) {
    int n1 = s1.size(), n2 = s2.size();
    int ans = INT_MAX;
    if (n2 > n1) return -1;
    for (int i = 0; i < n1 - n2 + 1; i++) {
        string temp = s1.substr(0, i) + s2 + s1.substr(i + n2);  
        int cost = 0;          
        for (int j = i; j < i + n2; j++) {
            if (s1[j] != temp[j]) cost++;
        }
        int z = 0;
        for (int j=0; j<ceil(n1 / 2.0); ++j) {
            if ((j < i || j >= i + n2) && temp[j] != temp[n1-j- 1]) 
                cost++;
            else if (temp[j] != temp[n1 - j - 1] && n1 - j - 1 < i || n1 - j - 1 >=  i + n2))
                cost++;
            else if (temp[j] != temp[n1 - j - 1]) {  
                z = 1;
                break;
            }
        }
        if (z == 0) ans = min(ans, cost);
    }
    if (ans == INT_MAX) return -1;
    else return ans;
}
int main() {
    return 0;
}