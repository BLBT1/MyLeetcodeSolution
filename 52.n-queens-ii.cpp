/*
 * @lc app=leetcode id=52 lang=cpp
 *
 * [52] N-Queens II
 */

// @lc code=start
class Solution
{
public:
    int totalNQueens(int n)
    {
        // dfs: each row has n place to put the queen
        int res = 0;
        vector<vector<char>> grid(n, vector<char>(n, '.'));
        dfs(grid, res, 0);
        return res;
    }

    void dfs(vector<vector<char>> &grid, int &res, int x)
    {
        if (x == grid.size())
        {
            ++res;
            return;
        }

        for (int y = 0; y < grid.size(); ++y)
        {
            if (isValid(grid, x, y))
            {
                grid[x][y] = 'Q';
                dfs(grid, res, x + 1);
                grid[x][y] = '.';
            }
        }
    }

    bool isValid(vector<vector<char>> &grid, int x, int y)
    {
        for (int row = 0; row < grid.size(); ++row)
            if (row != x && grid[row][y] == 'Q')
                return false;

        for (int col = 0; col < grid.size(); ++col)
            if (col != y && grid[x][col] == 'Q')
                return false;

        // only need to check leftUpper and rightUpper
        int k = 1;
        while (x - k >= 0 && y - k >= 0)
        {
            int row = x - k;
            int col = y - k;
            if (grid[row][col] == 'Q')
                return false;
            ++k;
        }

        k = 1;
        while (x - k >= 0 && y + k < grid.size())
        {
            int row = x - k;
            int col = y + k;
            if (grid[row][col] == 'Q')
                return false;
            ++k;
        }

        return true;
    }
};
// @lc code=end
