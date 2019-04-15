// https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/

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
    int maxAncestorDiff(TreeNode* root) {
        int ans = 0;
        traverse(root, INT_MAX, INT_MIN, ans);
        return ans;
    }
    
    void traverse(TreeNode* root, int minVal, 
                 int maxVal, int &ans) {
        if (!root) return;
        minVal = min(minVal, root->val);
        maxVal = max(maxVal, root->val);
        ans = max(ans, abs(minVal - maxVal));
        traverse(root->left, minVal, maxVal, ans);
        traverse(root->right, minVal, maxVal, ans);
    }
};

// accepted
