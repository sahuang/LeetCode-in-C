// https://leetcode.com/problems/remove-duplicates-from-sorted-list/
/*
Given a sorted linked list, delete all duplicates such that each element appear only once.

Example 1:

Input: 1->1->2
Output: 1->2
Example 2:

Input: 1->1->2->3->3
Output: 1->2->3
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
    ListNode* deleteDuplicates(ListNode* head) {

        if (!head) return head;
        ListNode* prev = head;
        ListNode* curr = head->next;
        while (curr) {
            while (curr && curr->val == prev->val) {
                curr = curr->next;
            }
            if (!curr) {
                prev->next = nullptr;
                return head;
            }
            prev->next = curr;
            prev = curr;
            curr = curr->next;
        }
        return head;
    }
};

/*
Runtime: 12 ms, faster than 100.00% of C++ online submissions for Remove Duplicates from Sorted List.
Memory Usage: 9.2 MB, less than 57.92% of C++ online submissions for Remove Duplicates from Sorted List.
*/
