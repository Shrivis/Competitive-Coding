#include<bits/stdc++.h>

using namespace std;


set<vector<int>> s;


int dist(int x1, int y1, int x2, int y2) {
    return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
}


void getRes(vector<int> c, int x, int y) {
    if (dist(x, y, c[0], c[1]) > c[2]*c[2]) return;
    if (s.count({x,y})) return;
    s.insert({x,y});
    getRes(c, x+1, y);
    getRes(c, x+1, y+1);
    getRes(c, x+1, y-1);
    getRes(c, x-1, y);
    getRes(c, x-1, y+1);
    getRes(c, x-1, y-1);
    getRes(c, x, y+1);
    getRes(c, x, y-1);
}


void countLatticePoints(vector<vector<int>>& circles) {
    for (auto& circle: circles) {
        getRes(circle, circle[0], circle[1]);
    }
}

int main() {
    vector<vector<int>> circles{{8,9,6},{9,8,4},{4,1,1},{8,5,1},{7,1,1},{6,7,5},{7,1,1},{7,1,1},{5,5,3}};
    countLatticePoints(circles);
    cout<<s.size()<<endl;
    for (auto& val: s) cout<<"["<<val[0]<<","<<val[1]<<']'<<", ";
    return 0;
}