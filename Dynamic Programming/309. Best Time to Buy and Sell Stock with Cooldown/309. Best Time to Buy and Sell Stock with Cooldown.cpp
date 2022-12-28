class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(3, 0));
        // set this to ensure the first purchase
        dp[0][0] = INT_MIN;
        for (int i = 0; i < n; ++i)
        {
            dp[i + 1][0] = max(dp[i][0], dp[i][2] - prices[i]);
            dp[i + 1][1] = dp[i][0] + prices[i];
            dp[i + 1][2] = max(dp[i][1], dp[i][2]);
        }
        return max(dp[n][2], dp[n][1]);
    }
};

// state
// 0 buy a stock
// 1 sell a stock
// 2 after first day after sell a stock