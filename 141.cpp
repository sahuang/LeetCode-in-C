// https://leetcode.com/problems/linked-list-cycle/
/*
Given a linked list, determine if it has a cycle in it.

To represent a cycle in the given linked list, we use an integer pos which represents the position (0-indexed) in the linked list where tail connects to. If pos is -1, then there is no cycle in the linked list.
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
    bool hasCycle(ListNode *head) {

        if (!head || !head->next) return false;
        ListNode* slow = head;
        ListNode* fast = head;
        while (slow) {
            slow = slow->next;
            if (!fast || !fast->next) break;
            fast = fast->next->next;
            if (slow && slow == fast) return true;
        }
        return false;
    }
};

// Accepted  12 ms  9.8 MB
