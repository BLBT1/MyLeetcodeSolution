/*
 * @lc app=leetcode id=673 lang=cpp
 *
 * [673] Number of Longest Increasing Subsequence
 */

// @lc code=start
class Solution
{
public:
    int findNumberOfLIS(vector<int> &nums)
    {
        const int n = nums.size();
        //{dp[i] = {length of LIS by i}}
        vector<int> dp(n, 1);
        vector<int> times(n, 1); // ways to reach ith point

        for (int i = 1; i < n; ++i)
        {
            int maxNum = 1;
            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j])
                {
                    if (dp[j] + 1 > dp[i]) // if len increased
                    {
                        dp[i] = dp[j] + 1;
                        maxNum = times[j];
                    }
                    //if len unchanged and other j match this curr max length
                    else if (dp[j] + 1 == dp[i])
                    {
                        maxNum += times[j]; // accumuate the times to reach there
                    }
                }
            }
            // update len and times
            times[i] = maxNum;
        }

        int maxLen = 1;
        int maxNum = 0;
        for (int i = 0; i < n; i++)
        {
            if (dp[i] > maxLen)
            {
                maxLen = dp[i];
                maxNum = times[i];
            }
            else if (dp[i] == maxLen)
                maxNum += times[i];
        }

        return maxNum;
    }
};
// @lc code=end
// return the number of LIS
//  [1, 3, 5, 4, 7]
//         i
//   j
//dp 1  2  3  1  1
//ti 1  1  1  1  1

// 1-> 3-> 4 ->7
// 1-> 3-> 5-> 7
//2 ways to get 7
// also record how many ways to reach this pt?
