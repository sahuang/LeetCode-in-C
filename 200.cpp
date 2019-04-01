// https://leetcode.com/problems/number-of-islands/

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        
        if (!grid.size() || !grid[0].size()) return 0;
        int row = grid.size();
        int col = grid[0].size();
        int count = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == '1') {
                    traverse(grid, row, col, i, j);
                    count++;
                }
            }
        }
        return count;
    }
    
    void traverse(vector<vector<char>>& grid, int row, int col,
                  int i, int j) {
        if (i < 0 || i >= row || j < 0 || j >= col) return;
        if (grid[i][j] == '0') return;
        grid[i][j] = '0';
        traverse(grid, row, col, i - 1, j);
        traverse(grid, row, col, i + 1, j);
        traverse(grid, row, col, i, j - 1);
        traverse(grid, row, col, i, j + 1);
    }
};
