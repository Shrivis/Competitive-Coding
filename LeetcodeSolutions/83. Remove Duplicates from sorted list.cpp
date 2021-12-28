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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *temp = head;
        ListNode *itr = head;
        while(itr) {
            if (itr->next && itr->next->val != itr->val) {
                temp->next = itr->next;
                temp = temp->next;
            }
            itr = itr->next;
        }
        if (temp) temp->next = NULL;
        return head;
    }
};