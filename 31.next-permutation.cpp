/*
 * @lc app=leetcode id=31 lang=cpp
 *
 * [31] Next Permutation
 */

// @lc code=start
class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        //* blp: before the last peak,\
        //* start from the second last in the nums
        int blp = nums.size() - 2;

        //* find the blp
        while (blp >= 0 &&
               nums[blp] >= nums[blp + 1])
            --blp;

        if (blp == -1)
        {
            //* then the given sequence is in dsc order
            std::reverse(nums.begin(), nums.end());
            return;
        }

        //* find the index of y,
        //* where y is the first greater than nums[blp]
        //* and on the right of blp
        int y = std::numeric_limits<int>::max();
        int idx = blp + 1;

        for (int i = idx; i < nums.size(); ++i)
        {
            if (nums[i] < y && nums[i] > nums[blp])
            {
                y = nums[i];
                idx = i;
            }
        }
        swap(nums[blp], nums[idx]);
        sort(nums.begin() + blp + 1, nums.end());
    }
};
// @lc code=end
