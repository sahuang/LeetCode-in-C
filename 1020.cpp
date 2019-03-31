// https://leetcode.com/problems/number-of-enclaves/
/*
Given a 2D array A, each cell is 0 (representing sea) or 1 (representing land)

A move consists of walking from one land square 4-directionally to another land square, or off the boundary of the grid.

Return the number of land squares in the grid for which we cannot walk off the boundary of the grid in any number of moves.



Example 1:

Input: [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
Output: 3
Explanation:
There are three 1s that are enclosed by 0s, and one 1 that isn't enclosed because its on the boundary.
Example 2:

Input: [[0,1,1,0],[0,0,1,0],[0,0,1,0],[0,0,0,0]]
Output: 0
Explanation:
All 1s are either on the boundary or can reach the boundary.
*/

class Solution {
public:
    int numEnclaves(vector<vector<int>>& A) {
        if (!A.size() || !A[0].size()) return 0;
        int m = A.size();
        int n = A[0].size();

        // for each 1 on the boundary traverse.
        // row
        for (int i = 0; i < n; i++) {
            if (A[0][i] == 1) {
                traverse(A, 0, i);
            }
            if (A[m - 1][i] == 1) {
                traverse(A, m - 1, i);
            }
        }
        // col
        for (int i = 0; i < m; i++) {
            if (A[i][0] == 1) {
                traverse(A, i, 0);
            }
            if (A[i][n - 1] == 1) {
                traverse(A, i, n - 1);
            }
        }

        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (A[i][j] == 1) ans++;
            }
        }
        return ans;
    }

    void traverse(vector<vector<int>>& A, int row, int col) {
        int m = A.size();
        int n = A[0].size();
        if (row < 0 || row >= m || col < 0 || col >= n) return;
        if (A[row][col] == 0) return;
        A[row][col] = 0;
        traverse(A, row - 1, col);
        traverse(A, row + 1, col);
        traverse(A, row, col - 1);
        traverse(A, row, col + 1);
    }
};

// accepted
