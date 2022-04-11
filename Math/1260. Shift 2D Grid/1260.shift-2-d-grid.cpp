/*
 * @lc app=leetcode id=1260 lang=cpp
 *
 * [1260] Shift 2D Grid
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> shiftGrid(vector<vector<int>> &grid, int k)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> res(n, vector<int>(m));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int j_ = (j + k) % m;           // (j + numbers of columns added)%m
                int i_ = (i + (j + k) / m) % n; // (i + numbers of rows added)%n

                res[i_][j_] = grid[i][j];
            }
        }
        return res;
    }
};
// @lc code=end
