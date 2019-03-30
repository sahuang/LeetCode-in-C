// https://leetcode.com/problems/sort-list/submissions/
/*
Sort a linked list in O(n log n) time using constant space complexity.

Example 1:

Input: 4->2->1->3
Output: 1->2->3->4
Example 2:

Input: -1->5->3->4->0
Output: -1->0->3->4->5
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
    ListNode* sortList(ListNode* head) {

        if (!head || !head->next) return head;
        // find mid-point
        ListNode* prev = nullptr;
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = nullptr;
        ListNode* l1 = sortList(head);
        ListNode* l2 = sortList(slow);
        return merge(l1, l2);
    }

    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* prev = dummy;
        ListNode* n1 = l1;
        ListNode* n2 = l2;
        while (n1 && n2) {
            if (n1->val <= n2->val) {
                prev->next = n1;
                prev = n1;
                n1 = n1->next;
            } else {
                prev->next = n2;
                prev = n2;
                n2 = n2->next;
            }
        }
        if (n1) prev->next = n1;
        else prev->next = n2;
        return dummy->next;
    }
};

/*
Runtime: 60 ms, faster than 53.87% of C++ online submissions for Sort List.
Memory Usage: 24.9 MB, less than 21.76% of C++ online submissions for Sort List.
*/
