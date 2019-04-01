// https://leetcode.com/problems/merge-k-sorted-lists/

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        if (!lists.size()) return nullptr;
        auto comp = [] (ListNode* a, ListNode* b) {
            return a->val > b->val;
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(comp)>
            pq(comp);
        for (auto i : lists) {
            if (i) {
                pq.push(i);
            }
        }
        ListNode* head = new ListNode(0);
        ListNode* prev = head;
        while (!pq.empty()) {
            ListNode* temp = pq.top();
            pq.pop();
            prev->next = temp;
            prev = prev->next;
            if (temp->next) pq.push(temp->next);
        }
        return head->next;
    }
};

/*
Runtime: 28 ms, faster than 94.32% of C++ online submissions for Merge k Sorted Lists.
Memory Usage: 11 MB, less than 99.63% of C++ online submissions for Merge k Sorted Lists.
*/
