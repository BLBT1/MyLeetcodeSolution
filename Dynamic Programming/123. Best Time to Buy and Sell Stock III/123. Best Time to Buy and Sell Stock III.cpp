class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(4, 0));
        // insert those two vals ahead so that the first stock would be purchased
        dp[0][0] = INT_MIN;
        dp[0][2] = INT_MIN;
        for (int i = 0; i < n; ++i)
        {
            dp[i + 1][0] = max(dp[i][0], -prices[i]); // pick the cheapest first stock
            dp[i + 1][1] = max(dp[i][0] + prices[i], dp[i][1]);
            dp[i + 1][2] = max(dp[i][1] - prices[i], dp[i][2]);
            dp[i + 1][3] = max(dp[i][2] + prices[i], dp[i][3]);
        }

        return *max_element(dp[n].begin(), dp[n].end());
    }
};

// def dp[i][j]: at i round with state j
// states:
//     0: first time just purchased
//     1: first time just sold
//     2: second time just purchased
//     3: second time just sold
