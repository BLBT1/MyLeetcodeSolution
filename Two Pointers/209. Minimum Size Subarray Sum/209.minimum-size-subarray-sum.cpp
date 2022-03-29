/*
 * @lc app=leetcode id=209 lang=cpp
 *
 * [209] Minimum Size Subarray Sum
 */

// @lc code=start
class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        //idea: 学习guan神的双指针风格
        // 右指针整体移动
        // 左指针伺机而动
        int left = 0;
        int right = 0;
        int sum = 0;
        int res = INT_MAX;

        // 右指针整体移动
        for (; right < nums.size(); ++right)
        {
            sum += nums[right];

            // 左指针伺机而动
            while (sum >= target)
            {
                res = min(res, right - left + 1);

                sum -= nums[left++];
            }
        }
        return res == INT_MAX ? 0 : res;
    }
};
// @lc code=end
