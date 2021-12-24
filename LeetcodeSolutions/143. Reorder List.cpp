/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        vector<ListNode*> nexts;
        ListNode* temp=head;
        while(temp->next) {
            nexts.push_back(temp->next);
            temp = temp->next;
        }
        temp = head;
        int front = 0;
        int back = nexts.size()-1;
        for (int i=0; i<nexts.size(); ++i) {
            if (i%2 == 0) temp->next = nexts[back--];
            else temp->next = nexts[front++];
            temp = temp->next;
        }
        temp->next = NULL;
    }
};