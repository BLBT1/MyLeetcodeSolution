/*
 * @lc app=leetcode id=442 lang=cpp
 *
 * [442] Find All Duplicates in an Array
 */

// @lc code=start
class Solution
{
public:
    vector<int> findDuplicates(vector<int> &nums)
    {
        //* indexing sort useful when:
        //* 1. <= vals <= n && nums.length == n
        //* 2. find missing or duplicate, etc

        //* main idea:
        //* sort val i to nums[i] as much as possible
        int n = nums.size();
        nums.insert(nums.begin(), 0);
        vector<int> res;

        for (int i = 1; i < nums.size(); ++i)
        {
            while (nums[i] != i &&
                   nums[nums[i]] != nums[i])
            {
                swap(nums[i], nums[nums[i]]);
            }
        } //for

        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] != i)
                res.push_back(nums[i]);
        }

        return res;
    }
};
// @lc code=end
