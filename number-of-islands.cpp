/*
https://leetcode.com/problems/number-of-islands
*/

class Solution {
public:
    void coverLand(vector<vector<char>>& grid, int i, int j, int n, int m) {
        if (i < 0 || j < 0 || i >= n || j >= m) return;
        if (grid[i][j] == '0' || grid[i][j] == '2') return;
        grid[i][j] = '2';
        coverLand(grid, i - 1, j, n, m);
        coverLand(grid, i, j - 1, n, m);
        coverLand(grid, i, j + 1, n, m);
        coverLand(grid, i + 1, j, n, m);
    }

    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0, n = grid.size(), m = grid[0].size();
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == '1') {
                    coverLand(grid, i, j, n, m);
                    ++cnt;
                }
            }
        }
        return cnt;
    }
};