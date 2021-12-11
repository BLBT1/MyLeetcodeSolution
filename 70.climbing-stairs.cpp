/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 */

// @lc code=start
class Solution
{
public:
    int climbStairs(int n)
    {
        // like 时间序列
        // 但是每次可以走一个台阶或2个
        // n step to top [0:n] totally n+1
        vector<int> dp(n + 1, 1);
        for (int i = 2; i < n + 1; ++i)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }
};
// @lc code=end

// n step = top
// each time 1 step or 2 step
// states def: 0->  take 1 step
//             1 -> take 2 step
// dp[i] = dp[i-1][1]