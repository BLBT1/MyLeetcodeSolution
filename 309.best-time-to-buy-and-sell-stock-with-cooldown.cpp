/*
 * @lc app=leetcode id=309 lang=cpp
 *
 * [309] Best Time to Buy and Sell Stock with Cooldown
 */

// @lc code=start
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        // 时间序列dp
        // state 0: holding a stock
        // state 1: just sold
        // state 2: ready to buy
        // 0 -> 1, 0 -> 0
        // 1 -> 2
        // 2 -> 0, 2 -> 2
        // STE
        //* dp[i][0] = max {dp[i-1][0], dp[i-1][2]-price[i]}
        //* dp[i][1] = max{dp[i-1][0] + price[i]}
        //* dp[i][2] = max{dp[i-1][1], dp[i-1][2]}

        //* HARDNESS: what initial state we should set
        int hold = INT_MIN;
        int sold = 0;
        int ready = 0;
        const int n = prices.size();
        for (int i = 0; i < n; ++i)
        {
            // store the yesterday states
            int past_hold = hold;
            int past_sold = sold;
            int past_ready = ready;

            hold = max(past_hold, past_ready - prices[i]);
            sold = past_hold + prices[i];
            ready = max(past_sold, past_ready);
        } //for

        return max(sold, ready);
    }
};
// @lc code=end
