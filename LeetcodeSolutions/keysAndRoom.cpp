#include <bits/stdc++.h>
using namespace std;

bool canVisitAllRooms(vector<vector<int>>& rooms) {
    vector<bool> vis(rooms.size(), false);
    vis[0] = true;
    queue<int> q;
    q.push(0);
    while(!q.empty()) {
        int curr = q.front();q.pop();
        for (int i=0; i<rooms[curr].size(); ++i) {
            if (rooms[curr][i] != -1) {
                q.push(rooms[curr][i]);
                rooms[curr][i] = -1;
                cout<<rooms[curr][i]<<" ";
                // vis[rooms[curr][i]] = true;
            }
        }
    }
    for (auto x: vis) 
        if (!x) return false;
    return true;
}

int main() {
    vector<vector<int>> room { {1}, {2}, {3}, {}};
    cout<<canVisitAllRooms(room)<<endl;;
}