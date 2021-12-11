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
    { //经典binary search
        int l = 0, r = nums.size() - 1;
        while (l < r)
        {
            int mid = l + (r - l + 1) / 2; // [0,1]   mid->1
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
