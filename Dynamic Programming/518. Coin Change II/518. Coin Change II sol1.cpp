class Solution
{
public:
    int change(int amount, vector<int> &coins)
    {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));
        coins.insert(coins.begin(), 0);
        for (int i = 0; i <= n; ++i)
            dp[i][0] = 1;
        for (int i = 1; i <= n; ++i)
        {
            for (int c = 1; c <= amount; ++c)
            {
                for (int k = 0; k * coins[i] <= c; ++k)
                {
                    dp[i][c] += dp[i - 1][c - coins[i] * k];
                }
            }
        }

        return dp[n][amount];
    }
};

// dp[i][c] => num of combo to get c using first i coins

// you have an infinite number of each kind of coin. => 完全背包

// for k = 0 ~ c/coins[i];
//     dp[i][c] += dp[i][c-coins[i]*k]