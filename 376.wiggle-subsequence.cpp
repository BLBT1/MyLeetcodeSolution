/*
 * @lc app=leetcode id=376 lang=cpp
 *
 * [376] Wiggle Subsequence
 */

// @lc code=start
class Solution
{
public:
    int wiggleMaxLength(vector<int> &nums)
    {
        //state 0: with i end seq is raising
        //state 1: with i end seq is falling
        int raise = 1;
        int fall = 1;
        const int n = nums.size();
        for (int i = 1; i < n; ++i)
        {
            int past_raise = raise;
            int past_fall = fall;
            if (nums[i - 1] < nums[i])
            {
                raise = past_fall + 1;
                fall = past_fall;
            }
            else if (nums[i - 1] > nums[i])
            {
                fall = past_raise + 1;
                raise = past_raise;
            }
        }

        return max(fall, raise);
    }
};
// @lc code=end
