// https://leetcode.com/problems/merge-two-sorted-lists/
/*
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

Example:

Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4
*/

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

        if (!l1) return l2;
        if (!l2) return l1;
        ListNode* h1 = l1;
        ListNode* h2 = l2;
        ListNode* head;
        if (h1->val <= h2->val) {
            head = h1;
            h1 = h1->next;
        } else {
            head = h2;
            h2 = h2->next;
        }
        ListNode* curr = head;

        while (h1 && h2) {
            if (h1->val <= h2->val) {
                curr->next = h1;
                curr = h1;
                h1 = h1->next;
            } else {
                curr->next = h2;
                curr = h2;
                h2 = h2->next;
            }
        }

        if (h1) curr->next = h1;
        else curr->next = h2;
        return head;
    }
};

/*
Runtime: 8 ms, faster than 100.00% of C++ online submissions for Merge Two Sorted Lists.
Memory Usage: 8.8 MB, less than 100.00% of C++ online submissions for Merge Two Sorted Lists.
*/
