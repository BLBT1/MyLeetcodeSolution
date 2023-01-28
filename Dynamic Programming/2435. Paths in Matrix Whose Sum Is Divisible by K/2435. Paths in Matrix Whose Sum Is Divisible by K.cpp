class Solution
{
    using LL = long long;

public:
    int numberOfPaths(vector<vector<int>> &grid, int k)
    {
        int m = grid.size();
        int n = grid[0].size();
        int mod = 1e9 + 7;
        int sum = 0;

        vector<vector<vector<LL>>> dp(m, vector<vector<LL>>(n, vector<LL>(k)));
        for (int i = 0; i < m; ++i)
        {
            sum += grid[i][0] % mod;
            dp[i][0][sum % k] = 1;
        }

        sum = 0;
        for (int j = 0; j < n; ++j)
        {
            sum += grid[0][j] % mod;
            dp[0][j][sum % k] = 1;
        }

        for (int i = 1; i < m; ++i)
            for (int j = 1; j < n; ++j)
                for (int r = 0; r < k; ++r)
                {
                    int t = ((r - grid[i][j]) % k + k) % k;
                    dp[i][j][r] = (dp[i - 1][j][t] + dp[i][j - 1][t]) % mod;
                }
        return dp[m - 1][n - 1][0];
    }
};
// dp[i][j][r] => path from (0,0) to (i,j) that is divided by k w/ remainder r

// dp[i][j][r] = dp[i-1][j][t]+dp[i][j-1][t]
// r = (t+grid[i][j])%k => t = ((r-grid[i][j]) % k+k)%k