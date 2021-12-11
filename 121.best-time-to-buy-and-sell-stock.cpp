/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        const int n = prices.size();
        int hold = INT_MIN;
        int sold = 0;
        for (int i = 0; i < n; ++i)
        {
            int old_hold = hold;
            int old_sold = sold;
            hold = max(old_hold, -prices[i]);
            sold = max(old_hold + prices[i], old_sold);
        }

        return max(hold, sold);
    }
};
// @lc code=end

// prices = [7,1,5,3,6,4]
//
// define states:
// 0-> holding max
// 1-> sold max

// dp[i][sold] = max{dp[i-1][hold] + price, dp[i-1][sold]}
// dp[i][hold] = max{dp[i-1][hold], -price}
// i = 0 i = 1
//
//
//