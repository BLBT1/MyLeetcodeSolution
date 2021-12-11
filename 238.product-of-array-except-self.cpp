/*
 * @lc app=leetcode id=238 lang=cpp
 *
 * [238] Product of Array Except Self
 */

// @lc code=start
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        // first loop: from left to right
        // second loop: from right to left
        // 每个pass：=*res【i】，再 curr与nums中对应位置相乘
        // idea: from left to right, the res[i] = 所有他右边数的乘积
        //      from right to left, the res[i] 补上所有他右边数的乘积
        int curr = 1;
        vector<int> res(nums.begin(), nums.end());
        // ->
        for (int i = 0; i < nums.size(); ++i)
        {
            if (i == nums.size() - 1)
            {
                res[i] = curr;
            }
            else if (i == 0)
            {
                curr *= nums[i];
            }
            else
            {
                res[i] = curr;
                curr *= nums[i];
            }
        } // first pass

        // <-
        curr = 1;
        for (int i = nums.size() - 1; i >= 0; --i)
        {
            if (i == 0)
            {
                res[i] = curr;
            }
            else if (i == nums.size() - 1)
            {
                curr *= nums[i];
            }
            else
            {
                res[i] *= curr;
                curr *= nums[i];
            }
        } // second pass

        return res;
    }
};
// @lc code=end

//[1,2,3,4]
// from left to right
// curr = 6;
// [1,1,2,6]
// from right to left
// curr = 124
//[1,2,3,4]
// [24,12,8,6]
//