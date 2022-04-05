/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 */

// @lc code=start
class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int i = 0;
        int t = 0;
        int j = nums.size() - 1;
        while (j >= t)
        {
            if (nums[t] == 0)
            {
                swap(nums[i], nums[t]);
                ++t;
                ++i;
            }
            else if (nums[t] == 2)
            {
                swap(nums[t], nums[j]);
                --j;
            }
            else
                ++t;
        } //while
    }
};
// @lc code=end
