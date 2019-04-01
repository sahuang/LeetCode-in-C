// https://leetcode.com/problems/swap-nodes-in-pairs/

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
    ListNode* swapPairs(ListNode* head) {
        
        if (!head || !head->next) return head;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* curr = head;
        while (curr && curr->next) {
            ListNode* temp = curr->next; // temp = 2
            prev->next = temp; // -1 -> 2
            ListNode* n = temp->next; // n = 3
            temp->next = curr; // 2 -> 1
            curr->next = n; // 1 -> 3
            prev = curr; // prev = 1
            curr = n;
        }
        return dummy->next;
    }
};
