class Solution
{
public:
    int cherryPickup(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int dp[n + 1][n + 1][n + 1];
        for (int i = 0; i <= n; ++i)
            for (int j = 0; j <= n; ++j)
                for (int x = 0; x <= n; ++x)
                    dp[i][j][x] = INT_MIN;

        dp[1][1][1] = grid[0][0];

        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                for (int x = 1; x <= n; ++x)
                {
                    int y = i + j - x;
                    if (y < 1 || y > n)
                        continue;
                    if (grid[i - 1][j - 1] == -1 || grid[x - 1][y - 1] == -1)
                    {
                        continue;
                    }
                    if (x == 1 && i == 1 && j == 1)
                    {
                        continue;
                    }
                    dp[i][j][x] = max(dp[i][j][x], dp[i][j - 1][x]);
                    dp[i][j][x] = max(dp[i][j][x], dp[i - 1][j][x - 1]);
                    dp[i][j][x] = max(dp[i][j][x], dp[i][j - 1][x - 1]);
                    dp[i][j][x] = max(dp[i][j][x], dp[i - 1][j][x]);
                    if (i == x && j == y)
                        dp[i][j][x] += grid[i - 1][j - 1];
                    else
                        dp[i][j][x] += grid[i - 1][j - 1] + grid[x - 1][y - 1];
                }
            }
        }
        return max(dp[n][n][n], 0);
    }
};
// 本题可以解读为，从左上角到右下角，找出两条可行的线路，使得两条线路采集到的cherry数量最多．如果两条线路有重复的部分，则只算一次
// dp[i][j][x][y] => path(i, j) and path(x, y)
// for(int i = 0; i < m; ++i)
//     for(int j = 0; j < n; ++j)
//         for(int x = 0; x < m; ++x)
//             for(int y = 0; y < n; ++y)
//                 dp[i][j][x][y] =
//                     max{dp[i][j-1][x][y-1],
//                         dp[i-1][j][x][y-1],
//                         dp[i-1][j][x-1][y],
//                         dp[i][j-1][x-1][y]}

// 我们发现这里可以做一个优化， 因为两个path的步数是一样的， 所以 y = i+j-x
// dp[i][j][x] 就够了
