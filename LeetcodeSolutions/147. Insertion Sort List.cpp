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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev;
        curr = curr->next;
        while(curr) {
            prev = head;
            while(prev !=  curr) {
                if (prev->val > curr->val) {
                    int temp = curr->val;
                    curr->val = prev->val;
                    prev->val = temp;
                } else prev = prev->next;
            }
            curr = curr->next;
        }
        return head;
    }
};