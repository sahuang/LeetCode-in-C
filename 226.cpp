// https://leetcode.com/problems/invert-binary-tree/
/*
Invert a binary tree.
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
    TreeNode* invertTree(TreeNode* root) {

        if (!root || (!root->left && !root->right)) return root;
        TreeNode* l = root->left;
        TreeNode* r = root->right;
        root->left = invertTree(r);
        root->right = invertTree(l);
        return root;
    }
};

/*
Runtime: 4 ms, faster than 100.00% of C++ online submissions for Invert Binary Tree.
Memory Usage: 9.1 MB, less than 64.72% of C++ online submissions for Invert Binary Tree.
*/
