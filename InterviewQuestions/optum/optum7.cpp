#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& prices) {
    int minprice = INT_MAX, maxprofit = 0;
    for (int i = 0; i < prices.size(); i++) {
        if (prices[i] < minprice)
            minprice = prices[i];
        else if (prices[i] - minprice > maxprofit)
            maxprofit = prices[i] - minprice;
    }
    return maxprofit;
}

int main() {
    vector<int> prices{3, 4, 65, 34, -34, 43, 34};
    cout << solve(prices) << endl;
}