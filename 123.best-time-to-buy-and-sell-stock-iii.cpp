/*
 * @lc app=leetcode id=123 lang=cpp
 *
 * [123] Best Time to Buy and Sell Stock III
 */

// @lc code=start
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        // 时间序列dp
        const int n = prices.size();
        //0-> just buy the first stock
        //1-> just sell the first stock
        //2-> just buy the second stock
        //3-> just sell the second stock
        vector<vector<int>> dp(n, vector<int>(4, 0));

        for (int i = 1; i < n; i++)
        {
            dp[i][0] = max(dp[i - 1][0], -prices[i]);
            dp[i][1] = max(dp[i - 1][0] + prices[i], dp[i - 1][1]);
            dp[i][2] = max(dp[i - 1][1] - prices[i], dp[i - 1][2]);
            dp[i][3] = max(dp[i - 1][3], dp[i - 1][2] + prices[i]);
        }

        return *max_element(dp[n - 1].begin(), dp[n - 1].end());
    }
};
// @lc code=end
