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
        int i = nums.size() - 1;
        while (i > 0 && nums[i] <= nums[i - 1])
        {
            --i;
        }

        if (i == 0)
        {
            sort(nums.begin(), nums.end());
            return;
        }
        --i;

        // find the first element after i greater than nums[i]
        int j = nums.size() - 1;
        while (j > i && nums[j] <= nums[i])
        {
            --j;
        }
        swap(nums[j], nums[i]);
        sort(nums.begin() + i + 1, nums.end());
    }
};

// [1,2,4,3,1]
// [1,3,1,2,4]
// @lc code=end
