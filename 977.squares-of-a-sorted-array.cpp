/*
 * @lc app=leetcode id=977 lang=cpp
 *
 * [977] Squares of a Sorted Array
 */

// @lc code=start
class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        const int n = nums.size();
        for (int i = 0; i < n; ++i)
            nums[i] = nums[i] * nums[i];

        sort(nums.begin(), nums.end());

        return nums;
    }
};
// @lc code=end
