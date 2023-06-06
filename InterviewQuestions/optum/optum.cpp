#include <bits/stdc++.h>
using namespace std;

int curr_len(int left, int right, int n, char s[]) {
    int i = left, j = right;
    while (i >= 0 && j < n && s[i] == s[j]) {
        i--;
        j++;
    }
    return (j - i - 1);
}

char* game(char* input1) {
    int n = strlen(input1);
    if (n == 1) return input1;
    int max_len = INT_MIN, start, end;
    for (int i = 0; i < n - 1; i++) {
        int odd = curr_len(i, i, n, input1);
        int even = curr_len(i, i + 1, n, input1);
        if (odd > max_len) {
            start = i - odd / 2;
            max_len = odd;
        }
        if (even > max_len) {
            start = i - even / 2 + 1;
            max_len = even;
        }
    }
    char res[max_len];
    memcpy(res, &input1[start], max_len);
    res[max_len] = '\0';
    return &res;

    // return input1.substr(start, len);
}

int main() {
    char x[] = "racecarss";
    char* res = &x;
    char ans = game(res);
    return 0;
}