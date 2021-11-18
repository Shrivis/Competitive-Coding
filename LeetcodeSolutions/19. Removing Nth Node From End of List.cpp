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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *temp;
        temp = head;
        int size=0;
        while(temp) {
            size++;
            temp = temp->next;
        }
        if (size == 1) return NULL;
        temp = head;
        while(n<size-1) {
            temp = temp->next;
            n++;
        }
        cout<<temp->val;
        if (n == size) head = head->next;
        else temp->next = temp->next->next;
        return head;
    }
};