/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> nexts;
        while(head) {
            if (nexts.count(head)) return head;
            else nexts.insert(head);
            head = head->next;
        }
        return NULL;
    }
};