#include <bits/stdc++.h>
using namespace std;

// vector<int> removeDuplicate(vector<int> arr, int days) {
//     while (days--) {
//         vector<int> next;
//         if (arr[1] == 1) next.push_back(1);
//         else next.push_back(0);
//         for (int i = 1; i < arr.size() - 1; ++i) {
//             if ((arr[i - 1] and arr[i + 1]) or (!arr[i - 1] and !arr[i + 1]))
//                 next.push_back(0);
//             else next.push_back(1);
//         }
//         if (arr[arr.size()-2] == 1) next.push_back(1);
//         else next.push_back(0);
//         arr = next;
//     }
//     return arr;
// }

vector<int> removeDuplicate(vector<vector<int>> tag, int k) {
    map<int,int> hash;
    vector<int> res;
    for (auto bag: tag) {
        unordered_set<int> uset;
        for (auto item: bag) uset.insert(item);
        for (auto item: uset) hash[item]++;
    }
    for (auto item: hash) {
        if (item.second >= k) {
            res.push_back(item.first);
        }
    }
    return res;
}


int main() {
    for (auto x :
         removeDuplicate({{4, 9, 2}, {9, 2, 3}, {5, 4, 2}, {9, 4, 2}}, 3))
        cout << x << " ";
    return 0;
}