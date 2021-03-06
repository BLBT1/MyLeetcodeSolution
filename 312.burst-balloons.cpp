/*
 * @lc app=leetcode id=312 lang=cpp
 *
 * [312] Burst Balloons
 */

// @lc code=start
class Solution
{
public:
    int maxCoins(vector<int> &nums)
    {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        auto dp = vector<vector<int>>(n + 2, vector<int>(n + 2, 0));

        for (int len = 1; len <= n; len++)
            for (int i = 1; i + len - 1 <= n; i++)
            {
                int j = i + len - 1;
                for (int k = i; k <= j; k++)
                    dp[i][j] = max(
                        dp[i][j],
                        dp[i][k - 1] + dp[k + 1][j] + nums[i - 1] * nums[k] * nums[j + 1]);
            }

        return dp[1][n];
    }
};
// @lc code=end

// [1 x i xxx j]