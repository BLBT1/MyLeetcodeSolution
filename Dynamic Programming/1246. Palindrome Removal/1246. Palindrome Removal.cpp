class Solution
{
public:
    int minimumMoves(vector<int> &arr)
    {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; ++i)
            dp[i][i] = 1;
        for (int i = 1; i < n; ++i)
            dp[i - 1][i] = (arr[i] == arr[i - 1]) ? 1 : 2;

        for (int len = 3; len <= n; ++len)
        {
            for (int i = 0; i + len - 1 < n; ++i)
            {
                int j = i + len - 1;
                dp[i][j] = dp[i][j - 1] + 1;
                for (int k = i; k < j; k++)
                {
                    if (arr[k] == arr[j])
                        if (k >= 1) // if some part need to be remove before k
                            dp[i][j] = min(dp[i][j], dp[i][k - 1] + max(1, dp[k + 1][j - 1]));
                        else
                            dp[i][j] = min(dp[i][j], max(1, dp[k + 1][j - 1]));
                }
            }
        }
        return dp[0][n - 1];
    }
};

// XXXX k XXXX
// i         j

// dp[i][j] => min number of move need to remove arr[i, j]
// for k in [i:j] :
//      dp[i][j] = min(dp[i][j], max(1, dp[i][k-1] + dp[k][j]))