class Solution
{
public:
    int mergeStones(vector<int> &stones, int K)
    {
        int n = stones.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(K + 1, INT_MAX)));

        vector<int> presum(n + 1, 0);
        presum[0] = 0;
        for (int i = 1; i <= n; ++i)
            presum[i] = presum[i - 1] + stones[i - 1];

        for (int i = 0; i < n; ++i)
            dp[i][i][1] = 0;

        for (int len = 2; len <= n; ++len)
        {
            for (int i = 0; i + len - 1 < n; ++i)
            {
                int j = i + len - 1;
                for (int k = 2; k <= K; ++k)
                {
                    for (int m = i; m < j; ++m)
                    {
                        // if any element in dp is INT_MAX, then it is not been updated, so not impossible
                        if (dp[i][m][1] != INT_MAX && dp[m + 1][j][k - 1] != INT_MAX)
                            dp[i][j][k] = min(dp[i][j][k], dp[i][m][1] + dp[m + 1][j][k - 1]);
                    }
                }
                if (dp[i][j][K] != INT_MAX)
                    dp[i][j][1] = dp[i][j][K] + presum[j + 1] - presum[i];
            }
        }

        return dp[0][n - 1][1] == INT_MAX ? -1 : dp[0][n - 1][1];
    }
};

// N => N-(k-1) => N - (k-1)*2 => ... => K => 1
// 所以可以把这个过程想成 把 N 分成K 个区区间， 每个区间 内自己合并， 最后在合成1

// 比如 stones = [3,5,1,2,6], k = 3
//                               idx: 0  1  2     3   4
// 最优解就是： 把 stone 分成 3 个区间 [{3, 5, 1}, {2}, {6}]
// 每个区间需要的cost: dp[0][2][1] + dp[3][3][1] + dp[4][4][1]

// dp[i][j][k]： 把 stones[i: j] 分成k个区间最少需要的cost

// 状态转移：想找出最好的办法把n分成k个区间， 最后再加起来 成为一个区间
// dp[i][j][k] = min (dp[i][m][1] + dp[m+1][j][k-1]) for m in [i:j]
// dp[i][j][1] = dp[i][j][k] + sum[i:j]

// res: dp[0][n-1][1]

// presum:
// [1, 3, 1]
// sum[1:2]
//  0  1  4  5
//     i     j+1
