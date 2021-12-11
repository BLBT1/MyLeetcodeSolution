/*
 * @lc app=leetcode id=174 lang=cpp
 *
 * [174] Dungeon Game
 */

// @lc code=start
class Solution
{
public:
    int calculateMinimumHP(vector<vector<int>> &dungeon)
    {
        //* core: 反向逆推
        const int n = dungeon.size();
        const int m = dungeon[0].size();
        // dp[i][j] -> min hp to be alive after eat the curr
        vector<vector<int>> dp(n, vector<int>(m, 1));

        for (int i = n - 1; i >= 0; --i)
        {
            for (int j = m - 1; j >= 0; --j)
            {
                // alive at most bottom-right
                if (i == n - 1 && j == m - 1)
                {
                    dp[i][j] = 1; // need at least one blood to be alive
                }
                else if (i == n - 1)
                {
                    dp[i][j] = dp[i][j + 1] - dungeon[i][j + 1];
                }
                else if (j == m - 1)
                {
                    dp[i][j] = dp[i + 1][j] - dungeon[i + 1][j];
                }
                else //gernal case
                {
                    dp[i][j] = min(dp[i][j + 1] - dungeon[i][j + 1],
                                   dp[i + 1][j] - dungeon[i + 1][j]);
                }
                dp[i][j] = max(1, dp[i][j]); //* any time, must be alive
            }
        }

        // the first one need to be eaten
        dp[0][0] = dp[0][0] - dungeon[0][0];
        dp[0][0] = max(dp[0][0], 1);

        return dp[0][0];
    }
};
// @lc code=end
