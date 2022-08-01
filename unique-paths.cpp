/*
#include <iostream>
#include <vector>

#define M 3
#define N 4

int main()
{
    // specify the default value to fill the vector elements
    int default_value = 1;

    // Using the fill constructor to initialize a two-dimensional vector
    // with a given default value
    std::vector<std::vector<int>> matrix(M, std::vector<int>(N, default_value));

    // print the two-dimensional vector

    return 0;
}

https://leetcode.com/problems/unique-paths/

*/

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int> > grid(m, vector<int>(n, 0));
        for (int r = 0; r < m; ++r) grid[r][0] = 1;
        for (int c = 0; c < n; ++c) grid[0][c] = 1;
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                grid[i][j] = grid[i - 1][j] + grid[i][j - 1];
            }
        }
        return grid[m - 1][n - 1];
    }
};