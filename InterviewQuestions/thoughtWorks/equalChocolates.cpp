#include<bits/stdc++.h>
using namespace std;

int solution(vector<int> chocolates, int M, int N) {
    unordered_map<int, long> hash;
    long res = 0;
    long sum = 0;
    hash[0] = sum;
    for (int i=0; i<N; ++i) {
        sum += chocolates[i];
        long curr = (int)(sum % M);
        if (hash.find(curr) == hash.end()) {
            hash[curr] = sum;
        } else {
            res = max(res, sum - hash[curr]);
        }
    }
    return (int)(res / M);
}


int main() {
    cout<<solution({1,2,3,4,5}, 4, 5);
    return 0;
}