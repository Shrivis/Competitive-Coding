#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& prices) {
    for (int i=1; i<prices.size(); ++i) {
        prices[i] += prices[i-1];
    }
    int minprice = INT_MAX, res = 0;
    int maxprofit = 0;
    for (int i = 0; i < prices.size(); i++) {
        if (prices[i] < minprice)
            minprice = prices[i];
        else if (prices[i] - minprice > maxprofit) {
            res = minprice;
            maxprofit = prices[i] - minprice;
        }
    }
    return res;
}

int main() {
    vector<int> prices{-4527,  -1579,  -38732, -43669, -9287,
                       -48068, -30293, -30867, 18677};
    cout << solve(prices);
    return 0;
}