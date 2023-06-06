#include <bits/stdc++.h>

using namespace std;

void getAllString(int n, string s, int i, vector<string> &res) {
    if (s.size() == n) {
        res.push_back(s);
        return;
    }
    if (i==0 or s[i-1] == 'A') {
        getAllString(n, s+'A', i+1, res);
        getAllString(n, s+'B', i+1, res);
    } else getAllString(n, s+'A', i+1, res);
}

string findString(int n, int m) {
    vector<string> res;
    string s = "";
    getAllString(n, s, 0, res);
    sort(res.begin(), res.end());
    for (auto s: res) cout<<s<<endl;
    cout<<endl;
    if (res.size() <= m) return "Not Valid\n";
    return res[m-1];
}

int main() {
    int n=2, m=2;
    cout<<findString(n, m)<<endl;
    return 0;
}