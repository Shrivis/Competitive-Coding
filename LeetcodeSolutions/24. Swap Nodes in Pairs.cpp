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
    ListNode* swapNodes(ListNode* head) {
        ListNode* other = head->next;
        head->next = other->next;
        other->next = head;
        if (head->next && head->next->next) 
            head->next = swapNodes(head->next);
        return other;
    }
public:
    ListNode* swapPairs(ListNode* head) {
        if (head && head->next)
        head = swapNodes(head);
        return head;
    }
};