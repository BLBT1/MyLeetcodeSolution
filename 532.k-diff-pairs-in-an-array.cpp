/*
 * @lc app=leetcode id=532 lang=cpp
 *
 * [532] K-diff Pairs in an Array
 */

// @lc code=start
class Solution
{
public:
    int findPairs(vector<int> &nums, int k)
    {
        int i = 0;
        int j = i + 1;
        const int n = nums.size();
        int count = 0;

        // use 2 ptr; need to sort it
        sort(nums.begin(), nums.end());

        for (; j < n;)
        {
            j = i + 1; // tricky

            while (j < n && nums[j] - nums[i] < k)
                ++j;

            if (j < n && nums[j] == nums[i] + k)
                count++;
            i++;

            //* remove dupllicates
            while (i < n && nums[i] == nums[i - 1])
                i++;
        } // for
        return count;
    }
};
// @lc code=end
