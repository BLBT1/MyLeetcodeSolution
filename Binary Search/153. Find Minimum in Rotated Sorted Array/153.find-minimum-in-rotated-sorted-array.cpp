/*
 * @lc app=leetcode id=153 lang=cpp
 *
 * [153] Find Minimum in Rotated Sorted Array
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
            else if (nums[mid] >= nums[l])
            {
                l = mid + 1;
            }
            else
            {
                r = mid;
            }
        }
        // if(l == r)
        // {
        return nums[l];
        // }
        // else
        // {
        //     return min(nums[l], nums[r]);
        // }
    }
};
// @lc code=end
