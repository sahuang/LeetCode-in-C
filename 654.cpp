// https://leetcode.com/problems/maximum-binary-tree/

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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if (nums.size() == 0) return nullptr;
        int maxIndex = findMax(nums);
        TreeNode* root = new TreeNode(nums[maxIndex]);
        if (maxIndex == 0) root->left = nullptr;
        else {
            vector<int> left(&nums[0], &nums[maxIndex]);
            root->left = constructMaximumBinaryTree(left);
        }
        if (maxIndex == nums.size() - 1) root->right = nullptr;
        else {
            vector<int> right(&nums[maxIndex + 1], &nums[nums.size()]);
            root->right = constructMaximumBinaryTree(right);
        }
        return root;
    }
    
    int findMax(vector<int> nums) {
        int ans = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[ans]) ans = i;
        }
        return ans;
    }
};

/*
Accepted
*/
