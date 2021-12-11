/*
 * @lc app=leetcode id=1186 lang=cpp
 *
 * [1186] Maximum Subarray Sum with One Deletion
 */

// @lc code=start
class Solution
{
public:
    int maximumSum(vector<int> &nums)
    {
        // state 0 -> not used the deletion
        // state 1-> used the deletion
        const int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(2, 0));

        int res = INT_MIN;
        // very tricky
        dp[0][0] = nums[0];
        dp[0][1] = 0;

        if (n == 1)
            return dp[0][0];

        for (int i = 1; i < n; ++i)
        {
            dp[i][0] = max(dp[i - 1][0] + nums[i], nums[i]);
            dp[i][1] = max(dp[i - 1][0], dp[i - 1][1] + nums[i]);
            res = max((dp[i][0], res), dp[i][1]);
        }

        res = max(max(dp[n - 1][0], res), dp[n - 1][1]);
        //cout << dp[n - 1][0];

        return res;
    }
};
// @lc code=end
