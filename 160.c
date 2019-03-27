// https://leetcode.com/problems/intersection-of-two-linked-lists/
/*
Write a program to find the node at which the intersection of two singly linked lists begins.
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        if (!headA || !headB) return nullptr;
        ListNode* a = headA;
        ListNode* b = headB;
        bool switchedA = false;

        while (true) {
            // possibly intersect
            if (a == b) return a;
            a = a->next;
            b = b->next;
            if (!a && switchedA) return nullptr;
            if (!a) {
                a = headB;
                switchedA = true;
            }
            if (!b) b = headA;
        }

        return nullptr;
    }
};

// Accepted  52 ms  16.6 MB
