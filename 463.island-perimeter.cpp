/*
 * @lc app=leetcode id=463 lang=cpp
 *
 * [463] Island Perimeter
 */

// @lc code=start
class Solution
{
public:
    int islandPerimeter(vector<vector<int>> &grid)
    {
        const int n = grid.size();
        const int m = grid[0].size();
        vector<vector<int>> cnt(n, vector<int>(m, 0));
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (grid[i][j] == 1)
                {
                    if (i != 0 && grid[i - 1][j] == 1)
                        cnt[i][j]++;
                    if (i != n - 1 && grid[i + 1][j] == 1)
                        cnt[i][j]++;
                    if (j != 0 && grid[i][j - 1] == 1)
                        cnt[i][j]++;
                    if (j != m - 1 && grid[i][j + 1] == 1)
                        cnt[i][j]++;
                }
            }
        }

        int res = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (grid[i][j] == 1)
                    res += (4 - cnt[i][j]);
            }
        }

        return res;
    }
};
// @lc code=end

//