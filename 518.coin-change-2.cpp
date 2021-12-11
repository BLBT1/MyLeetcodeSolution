/*
 * @lc app=leetcode id=518 lang=cpp
 *
 * [518] Coin Change 2
 */

// @lc code=start
class Solution
{

public:
    int change(int amount, vector<int> &coins)
    {
        // 这道题看起来很像dfs 但是其实是背包型dp的一种
        // 核心是 coins【i】可以取 0~k 次， where k = amount/coin【i】
        // 这里capacity 为 amount
        // amount can be 0 ~ amount, amount+1 possiblilities
        // dp[c] <- combination to reach c
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;

        // like 0/1 knapsack problem
        for (int i = 0; i < coins.size(); ++i)
        {
            for (int c = 1; c <= amount; ++c)
            {
                if (c >= coins[i])
                    dp[c] += dp[c - coins[i]];
            } //for
        }     //for

        return dp[amount];
    }
};
// @lc code=end

// amount = 5
// [1,2,5]
//    i
//    c = 4
//dp[(c-2)]