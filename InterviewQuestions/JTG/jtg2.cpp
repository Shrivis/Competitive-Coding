#include <bits/stdc++.h>
using namespace std;
string solve(string str) {
    string res = ""; 
    int i = 0, curr = 1, count_D = 0;  
    while (i < str.size()) {
        char ch = str[i];
        int j = i + 1;
        if (i == 0 && ch == 'I') {
            res += to_string(curr);
            curr++;
        }
        if (ch == 'D') count_D++;
        while (j < str.size() && str[j] == 'D') {
            count_D++;
            j++;
        }
        int k = count_D;
        while (count_D >= 0) res += to_string(curr + count_D--);
        curr += (k + 1);
        count_D = 0;
        i = j;
    }
    return res;
}

int main() {
    cout<<solve("IDIDI");
    return 0;
}