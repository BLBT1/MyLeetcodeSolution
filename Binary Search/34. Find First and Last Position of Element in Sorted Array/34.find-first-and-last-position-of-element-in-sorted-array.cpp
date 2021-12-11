/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */

// @lc code=start
class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        return {findFirst(nums, target),
                findLast(nums, target)};
    }

    int findFirst(vector<int> &nums, int target)
    {
        if (nums.size() == 0)
            return -1;
        int l = 0, r = nums.size() - 1;
        int mid;
        while (l < r)
        {
            mid = l + (r - l) / 2;
            if (nums[mid] >= target)
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
        if (nums[l] == target)
            return l;
        else
            return -1;
    }

    int findLast(vector<int> &nums, int target)
    {
        if (nums.size() == 0)
            return -1;
        int l = 0, r = nums.size() - 1;
        int mid;
        while (l < r)
        {
            mid = l + (r - l) / 2 + 1;
            if (nums[mid] > target)
                r = mid - 1;
            else
                l = mid;
        }

        if (nums[l] == target)
            return l;
        else
            return -1;
    }
};
// @lc code=end
//             r
// [5,7,7,8,8,10]
//  0 1 2 3 4 5
//  l
