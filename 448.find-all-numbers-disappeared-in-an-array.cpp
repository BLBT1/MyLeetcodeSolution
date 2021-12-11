/*
 * @lc app=leetcode id=448 lang=cpp
 *
 * [448] Find All Numbers Disappeared in an Array
 */

// @lc code=start
class Solution
{
public:
    vector<int> findDisappearedNumbers(vector<int> &nums)
    { // O(n)
        vector<int> res;
        nums.insert(nums.begin(), 0);
        // indexing sort?
        const int n = nums.size();
        int i = 1;
        while (i < n)
        {
            while (nums[i] != i && nums[i] != nums[nums[i]])
            {
                swap(nums[i], nums[nums[i]]);
            }
            ++i;
        }

        for (int i = 1; i < n; ++i)
        {
            if (nums[i] != i)
                res.push_back(i);
        }
        return res;
    }
};
// @lc code=end
