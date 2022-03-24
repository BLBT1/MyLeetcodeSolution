/*
 * @lc app=leetcode id=154 lang=cpp
 *
 * [154] Find Minimum in Rotated Sorted Array II
 */

// @lc code=start
class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int l = 0, r = nums.size() - 1;
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            if (nums[l] < nums[r])
            {
                return nums[l];
            }

            if (nums[mid] > nums[l])
            {
                l = mid + 1;
            }
            else if (nums[mid] < nums[l])
            {
                r = mid;
            }
            else
            {
                ++l;
            }
        }
        return nums[l];
    }
};
// @lc code=end
