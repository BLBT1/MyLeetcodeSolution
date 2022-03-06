/*
 * @lc app=leetcode id=162 lang=cpp
 *
 * [162] Find Peak Element
 */

// @lc code=start
class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        int l = 0;
        int r = nums.size() - 1;
        while (l < r)
        {
            int mid = l + (r - l + 1) / 2;
            if (nums[mid - 1] < nums[mid])
            {
                l = mid;
            }
            else
            {
                r = mid - 1;
            }
        }
        return l;
    }
};
// @lc code=end
