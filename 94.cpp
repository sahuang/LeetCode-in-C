// https://leetcode.com/problems/binary-tree-inorder-traversal/
/*
Given a binary tree, return the inorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,3,2]
Follow up: Recursive solution is trivial, could you do it iteratively?
*/

// recursive
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> out;
        traverse(out, root);
        return out;
    }

    void traverse(vector<int>& out, TreeNode* root) {
        if (!root) return;
        traverse(out, root->left);
        out.push_back(root->val);
        traverse(out, root->right);
    }
};

/*
Runtime: 4 ms, faster than 100.00% of C++ online submissions for Binary Tree Inorder Traversal.
Memory Usage: 9.4 MB, less than 21.90% of C++ online submissions for Binary Tree Inorder Traversal.
*/

// iterative
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {

        stack<TreeNode*> st;
        vector<int> out;

        while (!st.empty() || root) {
            while (root) {
                st.push(root);
                root = root->left;
            }
            root = st.top();
            st.pop();
            out.push_back(root->val);
            root = root->right;
        }
        return out;
    }
};

/*
Runtime: 4 ms, faster than 100.00% of C++ online submissions for Binary Tree Inorder Traversal.
Memory Usage: 9.1 MB, less than 87.01% of C++ online submissions for Binary Tree Inorder Traversal.
*/
