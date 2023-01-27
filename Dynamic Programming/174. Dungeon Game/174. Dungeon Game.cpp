class Solution
{
public:
    int calculateMinimumHP(vector<vector<int>> &dungeon)
    {
        // must ensure sure any time is alive
        // dp[i][j] = max(1, dp[i][j]);
        // so we need to go from bottn to up;
        int m = dungeon.size();
        int n = dungeon[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 1));
        for (int i = m - 1; i >= 0; --i)
        {
            for (int j = n - 1; j >= 0; --j)
            {
                if (i == m - 1 && j == n - 1)
                    dp[i][j] = 1;
                else if (j == n - 1)
                    dp[i][j] = dp[i + 1][j] - dungeon[i + 1][j];
                else if (i == m - 1)
                    dp[i][j] = dp[i][j + 1] - dungeon[i][j + 1];
                else
                    dp[i][j] = min(dp[i][j + 1] - dungeon[i][j + 1], dp[i + 1][j] - dungeon[i + 1][j]);
                dp[i][j] = max(dp[i][j], 1);
            }
        }
        dp[0][0] = dp[0][0] - dungeon[0][0];
        int res = max(dp[0][0], 1);
        return res;
    }
};