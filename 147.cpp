// https://leetcode.com/problems/insertion-sort-list/
/*
Sort a linked list using insertion sort.

Algorithm of Insertion Sort:

Insertion sort iterates, consuming one input element each repetition, and growing a sorted output list.
At each iteration, insertion sort removes one element from the input data, finds the location it belongs within the sorted list, and inserts it there.
It repeats until no input elements remain.

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
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = head;
        ListNode* curr = head->next;
        while (curr) {
            while (curr && curr->val >= prev->val) {
                prev = curr;
                curr = curr->next;
            }
            if (!curr) return dummy->next;
            prev->next = curr->next;
            ListNode* prevPos = dummy;
            ListNode* pos = dummy->next;
            while (curr->val > pos->val) {
                prevPos = pos;
                pos = pos->next;
            }
            prevPos->next = curr;
            curr->next = pos;
            curr = prev->next;
        }
        return dummy->next;
    }
};

/*
Runtime: 20 ms, faster than 98.61% of C++ online submissions for Insertion Sort List.
Memory Usage: 9.5 MB, less than 88.41% of C++ online submissions for Insertion Sort List.
*/
