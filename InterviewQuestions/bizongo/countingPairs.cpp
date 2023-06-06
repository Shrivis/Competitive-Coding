#include <bits/stdc++.h>
using namespace std;

int countPairs(vector<int> numbers, int k) {
    unordered_set<int> uset;
    unordered_set<string> res;
    for (auto num : numbers) uset.insert(num);
    for (auto num : numbers) {
        if (uset.count(num + k)) {
            string key = to_string(num) +"-"+to_string(num+k);
            res.insert(key);
        }
    }
    return res.size();
}

int main() { cout << countPairs({1, 1, 2, 2, 3, 3}, 1); }