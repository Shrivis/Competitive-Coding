#include <bits/stdc++.h>
using namespace std;

int helper(string word) {
    int i=0, count=1, res=0;
    while(i<word.size()) {
        if (word[i] == word[i-1]) {
            count++;
        } else {x
            res += count/2;
            count = 1;
        }
        i++;
    }
    res += count/2;
    return res;
}

vector<int> minimalOperations(vector<string> words) {
    vector<int> res;
    for (auto word: words) res.push_back(helper(word));
    return res;
}

int main() {
    for (auto x : minimalOperations({"ab", "aab", "abb", "abab", "abaaaba"}))
        cout << x << " ";
    return 0;
}