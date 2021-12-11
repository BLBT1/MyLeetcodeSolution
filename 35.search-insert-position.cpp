/*
 * @lc app=leetcode id=35 lang=cpp
 *
 * [35] Search Insert Position
 */

// @lc code=start
class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size();
        while (left < right)
        {
            int mid = (left + right) >> 1;
            if (nums[mid] > target)
            {
                right = mid;
            }
            else if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                return mid;
            }
        }
        return left;
    }
};
// @lc code=end
