// https://leetcode.com/problems/path-sum-ii/
/*
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

Note: A leaf is a node with no children.

Example:

Given the below binary tree and sum = 22,

      5
     / \
    4   8
   /   / \
  11  13  4
 /  \    / \
7    2  5   1
Return:

[
   [5,4,11,2],
   [5,8,4,5]
]
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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {

        vector<vector<int>> ans;
        if (!root) return ans;
        if (root->val == sum && !root->left
            && !root->right) ans.push_back({sum});

        vector<vector<int>> left = pathSum(root->left, sum-root->val);
        vector<vector<int>> right = pathSum(root->right, sum-root->val);
        for (int i = 0; i < left.size(); i++) {
            left[i].insert(left[i].begin(), root->val);
            ans.push_back(left[i]);
        }
        for (int i = 0; i < right.size(); i++) {
            right[i].insert(right[i].begin(), root->val);
            ans.push_back(right[i]);
        }
        return ans;
    }
};

/*
Runtime: 32 ms, faster than 38.00% of C++ online submissions for Path Sum II.
Memory Usage: 31.9 MB, less than 37.22% of C++ online submissions for Path Sum II.
*/
