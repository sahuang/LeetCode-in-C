// https://leetcode.com/problems/kth-smallest-element-in-a-bst/
/*
Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Note:
You may assume k is always valid, 1 ≤ k ≤ BST's total elements.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {

        stack<TreeNode*> st;
        int count = 0;
        while (!st.empty() || root) {
            while (root) {
                st.push(root);
                root = root->left;
            }
            root = st.top();
            st.pop();
            count++;
            if (count == k) return root->val;
            root = root->right;
        }

        return 0;
    }
};

/*
Runtime: 24 ms, faster than 99.22% of C++ online submissions for Kth Smallest Element in a BST.
Memory Usage: 21.6 MB, less than 63.75% of C++ online submissions for Kth Smallest Element in a BST.
*/
