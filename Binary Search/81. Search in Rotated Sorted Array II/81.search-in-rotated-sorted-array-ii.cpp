/*
 * @lc app=leetcode id=81 lang=cpp
 *
 * [81] Search in Rotated Sorted Array II
 */

// @lc code=start
class Solution
{
public:
    bool search(vector<int> &nums, int target)
    {
        // 与33唯一的不同是这题目中有重复数字
        // 所以遇到重复的数字我们可以减少区间
        int l = 0, r = nums.size() - 1;
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target)
            {
                return true;
            }
            else if (nums[mid] == nums[l])
            {
                l++;
            }
            else if (nums[mid] == nums[r])
            {
                r--;
            }
            else
            {
                // like 33
                if (nums[mid] >= nums[l])
                {
                    if (nums[l] <= target && target <= nums[mid])
                    {
                        r = mid;
                    }
                    else
                    {
                        l = mid + 1;
                    }
                }
                else
                {
                    if (nums[mid] < target && target <= nums[r])
                    {
                        l = mid + 1;
                    }
                    else
                    {
                        r = mid;
                    }
                }
            }
        }
        if (nums[l] == nums[r] && nums[l] == target)
        {
            return true;
        }
        return false;
    }
};
// @lc code=end
