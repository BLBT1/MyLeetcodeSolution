/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 */

// @lc code=start
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        //时间序列dp
        // dp[i][j] <= 第i轮 第j种状态
        // 0: the max money without rob this house
        // 1: the max money rob this house
        vector<vector<int>> dp(nums.size(), vector<int>(2, 0));
        dp[0][1] = nums[0];
        const int n = nums.size();
        for (int i = 1; i < nums.size(); ++i)
        {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
            dp[i][1] = dp[i - 1][0] + nums[i];
        } //for

        return max(dp[n - 1][0], dp[n - 1][1]);
    }
};
// @lc code=end
