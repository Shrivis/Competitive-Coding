 #include<bits/stdc++.h>

 using namespace std;
 
 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

 int main() {
    ListNode* start = new ListNode(6);
    ListNode* itr = start;
    vector<int> nums{8, 9, 2, 4, 3};
    for (auto num: nums) {
        ListNode*temp = new ListNode(num);
        itr->next = temp;
        itr = itr->next;
    }
    itr = start;
    ListNode* p;
    ListNode* head = start;
    p = start->next->next;
    start->next->next = p->next;
    p->next->next = p;
    cout<<start->next->next->next->val<<endl;
    int i=2;
    while(head and i++<10) {
        cout<<head->val<<" ";
        head = head->next;
    }
    return 0;

 }