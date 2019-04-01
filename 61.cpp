// https://leetcode.com/problems/rotate-list/

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
    ListNode* rotateRight(ListNode* head, int k) {
        
        if (!head || !head->next || k == 0) return head;
        int count = 0;
        ListNode* curr = head;
        while (curr) {
            count++;
            curr = curr->next;
        }
        k %= count;
        if (k == 0) return head;
        curr = head;
        for (int i = 0; i < count - k - 1; i++) {
            curr = curr->next;
        }
        ListNode* temp = curr->next;
        curr->next = nullptr;
        curr = temp;
        while (curr->next) curr = curr->next;
        curr->next = head;
        return temp;
    }
};
