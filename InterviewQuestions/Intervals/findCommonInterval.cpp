#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define rep(i, n) for (int i=0; i<n; ++i)

struct comp {
    bool operator() (pii const& a, pii const& b) {
        return a.first > b.first;
    }
};

pii getTime(string event) {
    int n = event.size();
    int t1 = ((event[n-11]-'0')*10+(event[n-10]-'0'))*60 + (event[n-8]-'0')*10+(event[n-7]-'0');
    int t2 = ((event[n-5]-'0')*10+(event[n-4]-'0'))*60 + (event[n-2]-'0')*10+(event[n-1]-'0');
    return {t1, t2};
}

string getEarliesMeettime(vector<string> events, int k) {
    if (events.size() == 0) return "00:00";
    priority_queue<pii, vector<pii>, comp> pq;
    vector<pii> busy;
    for (auto event: events) pq.push(getTime(event));
    pq.push({1440, 1440});
    busy.push_back(pq.top());
    pq.pop();
    while(!pq.empty()) {
        pii curr = pq.top(); pq.pop();
        if (curr.first > busy.back().second) busy.push_back(curr);
        else busy.back().second = max(busy.back().second, curr.second);
    }
    if (busy[0].first > k) return "00:00";
    for (int i=0; i<busy.size()-1; ++i) {
        if ((busy[i+1].first-busy[i].second) > k) {
            string hour = to_string((busy[i].second+1)/60);
            string min = to_string((busy[i].second+1)%60);
            if (hour.size() == 1) hour = '0'+hour;
            if (min.size() == 1) min = '0'+min;
            return hour+":"+min;            
        }
    }
    return "-1";
}

int main() {
    vector<string> events{
        "shrivis codes 00:00 04:00",
        "shrivis codes 05:00 06:10",
        "shrivis codes 08:49 14:00",
        "shrivis codes 16:58 17:59",
        "shrivis codes 22:00 22:05"
    };
    cout<<getEarliesMeettime(events, 180)<<endl;
    return 0;
}