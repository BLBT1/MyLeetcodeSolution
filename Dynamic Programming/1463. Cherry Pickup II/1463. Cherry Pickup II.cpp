class Solution
{
public:
    int cherryPickup(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MIN / 2));
        dp[0][n - 1] = grid[0][0] + grid[0][n - 1];
        // t => each round, as two robots always move down
        for (int t = 1; t < m; ++t)
        {
            auto old_dp = dp;
            for (int i = 0; i < n; ++i)
            {
                for (int j = 0; j < n; ++j)
                {
                    dp[i][j] = INT_MIN / 2;
                    for (int a = i - 1; a <= i + 1; a++)
                        for (int b = j - 1; b <= j + 1; b++)
                        {
                            if (a < 0 || a >= n || b < 0 || b >= n)
                                continue;
                            if (i == j)
                                dp[i][j] = max(dp[i][j], old_dp[a][b] + grid[t][i]);
                            else
                                dp[i][j] = max(dp[i][j], old_dp[a][b] + grid[t][i] + grid[t][j]);
                        }
                }
            }
        }
        int res = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                res = max(res, dp[i][j]);
            }
        }

        return res;
    }
};

// 每次机器人都必须向下一个，所以只需要记录横坐标就可以
// dp[i][j] => r1 at i, r2 at j, best collection
