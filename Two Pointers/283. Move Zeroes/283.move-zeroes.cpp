/*
 * @lc app=leetcode id=283 lang=cpp
 *
 * [283] Move Zeroes
 */

// @lc code=start
class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int i = 0, j = 0;
        while (j < nums.size() && nums[j] == 0)
            j++;
        while (i < nums.size())
        {
            if (nums[i] == 0)
            {
                if (j < nums.size())
                    swap(nums[i], nums[j]);
            }
            ++j;
            while (j < nums.size() && nums[j] == 0)
                ++j;
            ++i;
        }
    }
};

// [1,0,1]
//    i
//  j

// i the element we examine
// j last element that is not 0
// [1,3,12,0,0]
//         i
//              j

// @lc code=end
