#include<bits/stdc++.h>

using namespace std;

void insertAtBottom(int num, stack<int>& st) {
    if (st.empty()) {
        st.push(num);
        return;
    } else {
        int a = st.top();
        st.pop();
        insertAtBottom(num, st);
        st.push(a);
    }
}

void reverse(stack<int>& st) {
    if (!st.empty()) {
        int a = st.top();
        st.pop();
        reverse(st);
        insertAtBottom(a, st);
    }
}

int main () {
    stack<int> st;
    for (int i=0; i<10; ++i) st.push(i);
    reverse(st);
    while(!st.empty()) {
        cout<<st.top()<<" ";
        st.pop();
    }
    return 0;
}
