/*
 * @lc app=leetcode id=540 lang=cpp
 *
 * [540] Single Element in a Sorted Array
 */

// @lc code=start
class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        //* idea: using bsearch
        int l = 0, r = nums.size() - 1;
        while (l < r)
        {
            const int m = (l + r) >> 1;
            int n = m ^ 1;
            //* that is
            //* if m is odd, n = m - 1
            //* otherwise, n = m + 1
            if (nums[m] == nums[n])
                l = m + 1;
            else
                r = m;
        }
        return nums[l];
    }
};
// @lc code=end
