/*
 * @lc app=leetcode id=300 lang=cpp
 *
 * [300] Longest Increasing Subsequence
 */

// @lc code=start
class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        // save by dp: O(n^2), can be better(O(nlogn))
        const int n = nums.size();
        vector<int> dp(n, 1); //any seq must has length >= 1 (itself)
        for (int i = 1; i < n; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (nums[j] < nums[i])
                    dp[i] = max(dp[j] + 1, dp[i]);
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};
// @lc code=endS
// a seq is derived from an array from by adding/ deleting ...
// nums = [10,9,2,5,3,7,101,18]
// [2,3,7,101] -> length of 4
// ith turn, find j in [0...i-1] that is longest but less than nums[i]
//