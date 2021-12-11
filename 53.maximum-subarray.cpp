/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

// @lc code=start
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        //基本的时间序列dp
        // kadane's algo
        int res = nums[0];
        const int n = nums.size();
        vector<int> dp(n, INT_MIN);
        dp[0] = nums[0];
        for (int i = 1; i < n; ++i)
        {
            dp[i] = max(dp[i - 1] + nums[i],
                        nums[i]);

            res = max(res, dp[i]);
        }

        return res;
    }
};
// @lc code=end

//[-2, 1, -3, 4, -1, 2, 1, -5, 4]
