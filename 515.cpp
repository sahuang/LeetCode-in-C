// https://leetcode.com/problems/find-largest-value-in-each-tree-row/
/*
You need to find the largest value in each row of a binary tree.

Example:

Input:

          1
         / \
        3   2
       / \   \
      5   3   9

Output: [1, 3, 9]
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
    vector<int> largestValues(TreeNode* root) {
        vector<vector<int>> v;
        makeVec(v, root, 1);
        vector<int> out;
        for (auto i : v) {
            out.push_back(findMax(i));
        }
        return out;
    }

    int findMax(vector<int> v) {
        int max = v[0];
        for (int i = 1; i < v.size(); i++)
            max = (v[i] > max)?v[i]:max;
        return max;
    }

    void makeVec(vector<vector<int>>& v, TreeNode* root, int depth) {
        if (!root) return;
        if (v.size() < depth) {
            vector<int> temp;
            v.push_back(temp);
        }
        v[depth-1].push_back(root->val);
        makeVec(v, root->left, depth + 1);
        makeVec(v, root->right, depth + 1);
    }
};

/*
Runtime: 24 ms, faster than 82.21% of C++ online submissions for Find Largest Value in Each Tree Row.
Memory Usage: 23 MB, less than 17.02% of C++ online submissions for Find Largest Value in Each Tree Row.
*/
