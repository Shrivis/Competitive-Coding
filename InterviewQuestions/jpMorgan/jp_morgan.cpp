#include<bits/stdc++.h>

using namespace std;

vector<pair<int,int>> maxLecture(vector<int> scheduleStart, vector<int> scheduleEnd) {
    map<int, vector<pair<int,int>>> hash;
    vector<pair<int,int>> chosed;
    int res = 0;
    for (int i=0; i<scheduleStart.size(); ++i) {
        hash[scheduleEnd[i]-scheduleStart[i]].push_back({scheduleStart[i], scheduleEnd[i]});
    }
    for (auto & keyVal: hash) {
        cout<<keyVal.first<<": ";
        for (auto& [si, fi]: keyVal.second) cout<<'('<<si<<','<<fi<<')'<<", ";cout<<endl;
    }
    for (auto& keyVal: hash) {
        for (auto& [si, fi]: keyVal.second) {
            bool canAdd = true;
            for(auto& [sj, fj]: chosed) {
                if (((si >= sj && si < fj)|| (fi > sj && fi <= fj)) ||
                    ((sj >= si && sj < fi)|| (fj > si && fj <= fi)))
                    canAdd = false;
            }
            if (canAdd) {
                res++;
                chosed.push_back({si, fi});
            }
        }
    }
    return chosed;
}

vector<vector<int>> zip(vector<int> x, vector<int> y) {
    cout<<"got called";
    return {x, y};
}

int main() {
    vector<int> scheduleStart{1,3,2,5,4,5,7,6,8,2,12,9};
    vector<int> scheduleEnd  {4,4,7,8,8,9,9,10,11,12,13,12};
    // for (auto x:scheduleEnd ,auto y: scheduleEnd) cout<<x<<" "<<y<<endl;  ju7
    for (auto row:maxLecture(scheduleStart, scheduleEnd)) {
        cout<<'['<<row.first<<','<<row.second<<']'<<", ";
    }
    return 0;
}