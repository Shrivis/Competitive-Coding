#include <bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> locations, vector<int> movedFrom, vector<int> movedTo) {
    set<int> dataLoc;
    for (int loc: locations) dataLoc.insert(loc);
    for (int i=0; i<movedFrom.size(); ++i) {
        dataLoc.erase(movedFrom[i]);
        dataLoc.insert(movedTo[i]);
    }
    vector<int> finalLoc;
    for (auto x: dataLoc) finalLoc.push_back(x);
    return finalLoc;
}

int main() {
    for (auto x: solve({1,7,6,8}, {1,7,2}, {2,9,5})) {
        cout<<x<<" ";
    }
    cout<<endl;
}

