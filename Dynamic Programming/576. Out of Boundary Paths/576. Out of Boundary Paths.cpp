class Solution
{
public:
    int findPaths(int m, int n, int maxMove,
                  int startRow, int startColumn)
    {
        long long res = 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[startRow][startColumn] = 1;
        int mod = 1e9 + 7;
        if (maxMove == 0)
            return 0;
        for (int move = 1; move < maxMove; ++move)
        {
            // check borders
            for (int i = 0; i < m; ++i)
            {
                res = (res + dp[i][0]) % mod;
                res = (res + dp[i][n - 1]) % mod;
            }
            for (int j = 0; j < n; ++j)
            {
                res = (res + dp[0][j]) % mod;
                res = (res + dp[m - 1][j]) % mod;
            }
            auto prev_dp = dp;
            for (int i = 0; i < m; ++i)
            {
                for (int j = 0; j < n; ++j)
                {
                    dp[i][j] = 0;
                    long long top = (i - 1 < 0) ? 0 : prev_dp[i - 1][j];
                    long long bottom = (i + 1 >= m) ? 0 : prev_dp[i + 1][j];
                    long long left = (j - 1 < 0) ? 0 : prev_dp[i][j - 1];
                    long long right = (j + 1 >= n) ? 0 : prev_dp[i][j + 1];
                    dp[i][j] += (top + bottom + left + right) % mod;
                }
            }
        }
        for (int i = 0; i < m; ++i)
        {
            res = (res + dp[i][0]) % mod;
            res = (res + dp[i][n - 1]) % mod;
        }
        for (int j = 0; j < n; ++j)
        {
            res = (res + dp[0][j]) % mod;
            res = (res + dp[m - 1][j]) % mod;
        }
        return res % mod;
    }
};

// 思路1，从里面往外走
// dp[t][i][j] => num of way to get this point at t step
// res = sum{border+1}
//   X X X
// X 1 1 1 X
// X 1 1 1 X
// X 1 1 1 X
//   X X X
//
// // X X X
//    1 1 1

// 2
// 0 1 0

// 6
// 1 0 1

// 4
// 0 2 0

// res = 2+ 3 + 2+ 2+3+2+2+2 =
// 思路2, 从界外往里走
// 3
// 8
// 0
// 2
// 0