/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */

// @lc code=start
class Solution
{
public:
    int first_appear(vector<int> &nums, int target)
    {
        int l = 0;
        int r = nums.size() - 1;
        int mid;
        while (l < r)
        {
            mid = (r - l) / 2 + l;
            if (nums[mid] < target)
            {
                l = mid + 1;
            }
            else if (nums[mid] > target)
            {
                r = mid - 1;
            }
            else
            {
                r = mid;
            }
        }

        if (l == r && nums[l] == target)
        {
            return l;
        }
        else
        {
            return -1;
        }
    }

    int last_appear(vector<int> &nums, int target)
    {
        int l = 0;
        int r = nums.size() - 1;
        int mid;
        while (l < r)
        {
            mid = (r - l + 1) / 2 + l;
            if (nums[mid] < target)
            {
                l = mid + 1;
            }
            else if (nums[mid] > target)
            {
                r = mid - 1;
            }
            else
            {
                l = mid;
            }
        }
        if (l == r && nums[l] == target)
        {
            return l;
        }
        else
        {
            return -1;
        }
    }

    //[2,2]
    // l r
    //3
    vector<int> searchRange(vector<int> &nums, int target)
    {
        if (nums.empty())
            return {-1, -1};
        // find the position of first appear
        int first = first_appear(nums, target);
        // find the last appear of the element
        int last = last_appear(nums, target);

        return {first, last};
    }
};
// @lc code=end
