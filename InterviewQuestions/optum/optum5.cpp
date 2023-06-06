#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string currWord) {
    int n = currWord.length();
    for (int i=0; i<n/2; ++i) {
        if (currWord[i] != currWord[n-i-1]) return false;
    }
    return true;
}

vector<string> getPalindrome(string s) {
    vector<string> ans;
    string currWord = "";
    for (int i=0; i<s.size(); ++i) {
        if (s[i] != ' ') currWord += s[i];
        else {
            if (isPalindrome(currWord)) {
                ans.push_back(currWord);
            }
            currWord = "";
        }
    }
    // last word
    if(isPalindrome(currWord)) ans.push_back(currWord);
    return ans;
}

int main() {
    string s = "I want to be a racecar driver racecar";
    for (auto p: getPalindrome(s)) {
        cout<<p<<" ";
    }
    cout<<endl;
    return 0;
}