/*
 * @lc app=leetcode id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
 */

// @lc code=start
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        if (nums.size() == 1)
            return 1;
        if (nums.size() == 0)
            return 0;
        int slow = 0;
        for (int fast = 1; fast < nums.size(); ++fast)
        {
            if (nums[fast] != nums[slow])
            {
                nums[++slow] = nums[fast];
            }
        }

        return slow + 1;
    }
};
// @lc code=end
//         s
//[0,1,2,3,4,2,2,3,3,4]
//                   f