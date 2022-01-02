/*
 * @lc app=leetcode id=416 lang=cpp
 *
 * [416] Partition Equal Subset Sum
 */

// @lc code=start
class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        const int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 == 1)
            return false;
        vector<bool> dp(sum / 2, false);
        dp[0] = true;
        for (auto x : nums) // traverse over every given items
        {
            vector<bool> dp_temp = dp;
            for (int s = 0; s <= sum / 2; ++s) // traverse over all possible capacity
            {
                if (s - x >= 0 && dp_temp[s - x])
                {
                    dp[s] = true;
                }
            }
        }
        return dp[sum / 2];
    }
};
// @lc code=end
