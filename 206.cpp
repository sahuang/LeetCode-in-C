// https://leetcode.com/problems/reverse-linked-list/
/*
Reverse a singly linked list.

Example:

Input: 1->2->3->4->5->NULL
Output: 5->4->3->2->1->NULL
Follow up:

A linked list can be reversed either iteratively or recursively. Could you implement both?
*/

// Iterative
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
    ListNode* reverseList(ListNode* head) {

        if (!head || !head->next) return head;
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr->next) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        curr->next = prev;
        return curr;
    }
};

// Accepted  8 ms  9.1 MB

// example
// 1->2->3->4->NULL
// prev = NULL, curr = 1
// temp = 2, 1->NULL, prev = 1, curr = 2
// temp = 3, 2->1, prev = 2, curr = 3
// temp = 4, 3->2, prev = 3, curr = 4
// 4->3



// Recursive
class Solution {
public:
    ListNode* reverseList(ListNode* head) {

        if (!head || !head->next) return head;
        ListNode* p = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return p;
    }
};

// Accepted  12 ms  9.3 MB
